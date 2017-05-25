<?php

class CaracolGalleryMigration extends CaracolNodeMigration {

  public function __construct(array $arguments) {
    //************************
    //    We can create new fieds here
    //************************
//     $this->sourceFields['lead_graphic'] = 'Lead graphic string from D6';
//     $this->sourceFields['summary'] = 'Summary string from D6';

    parent::__construct($arguments);

//    $this->addFieldMapping('body', 'body');
//    $this->addFieldMapping('body:summary', 'teaser');
    $this->addFieldMapping('body:format')
        ->callbacks(array($this, 'caracolMapFormat'))
        ->defaultValue('3');
    
    $this->addFieldMapping('field_lead', 'teaser');

    //************************
    // We are only going to migrate the tags vocabulary,
    // Sections vocabulary contains terms that already exists as tags
    //************************
    $this->addFieldMapping('field_tags', '54')
        ->sourceMigration('tags');
    $this->addFieldMapping('field_tags:source_type')
        ->defaultValue('tid');

    $this->addFieldMapping('field_torneo', '53')
        ->sourceMigration('section_ligas');
    
    $this->addFieldMapping('field_torneo:source_type')
        ->defaultValue('tid');
    
    
    $this->addFieldMapping( 'field_gallery_images', 'field_imagenes')
      ->sourceMigration('gallery_images');
    $this->addFieldMapping('field_gallery_images:file_class')
      ->defaultValue('CaracolMigrateFileFid');
    
    $this->addFieldMapping( 'field_gallery_images:alt', 'field_imagenes:title');
    $this->addFieldMapping( 'field_gallery_images:title', 'field_imagenes:alt');
    $this->addFieldMapping( 'field_gallery_images:preserve_files', 1);
    
  }

  /**
   * Override the default D5 query to remove unused joins
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
        ->select('node', 'n')
        ->fields('n', array('nid', 'vid', 'title',
          'uid', 'status', 'created', 'changed', 'comment', 'promote',
          'moderate', 'sticky'))
        ->condition('n.type', $this->sourceType)
        ->orderBy('n.changed');
    $query->innerJoin('node_revisions', 'nr', 'n.vid=nr.vid');
    $query->fields('nr', array('body', 'format'));
    // Pick up simple CCK fields
    $cck_table = 'content_type_' . $this->sourceType;
    if (Database::getConnection('default', $this->sourceConnection)
            ->schema()->tableExists($cck_table)) {
      $query->leftJoin($cck_table, 'f', 'n.vid=f.vid');
      // The main column for the field should be rendered with
      // the field name, not the column name (e.g., field_foo rather
      // than field_foo_value).
      $field_info = $this->version->getSourceFieldInfo();
      foreach ($field_info as $field_name => $info) {
        if (isset($info['columns']) && !$info['multiple'] && $info['db_storage']) {
          $i = 0;
          foreach ($info['columns'] as $display_name => $column_name) {
            if ($i++ == 0) {
              $query->addField('f', $column_name, $field_name);
            }
            else {
              // The database API won't allow colons in column aliases, so we
              // will accept the default alias, and fix up the field names later.
              // Remember how to translate the field names.
              $clean_name = str_replace(':', '_', $display_name);
              $this->fixFieldNames[$clean_name] = $display_name;
              $query->addField('f', $column_name);
            }
          }
        }
      }
    }
    
    $query->leftJoin('nodeteaser', 'nt', 'n.nid=nt.nid');
    $query->fields('nt', array('teaser'));
    // $query->condition('n.nid', array(279588, 93743), 'IN');
    return $query;
  }

  /**
   * Callback function that returns a fixed value for the D7 format
   */
  function caracolMapFormat($format) {
    $result = 'full_html';
    return $result;
  }


  /**
   * This method is being called just after getting the records from the D5 database
   */
  function prepareRow($row) {
    parent::prepareRow($row);
  }

  
  /**
   * This method is being called just before saving the records into the D7 database
   */
  public function prepare($entity, $source_row) {
    $term_id = $entity->field_torneo;
    $bundle = $this->getLpckBundle($term_id);
    $lpck_id = $this->getLpckId($term_id);
    
    if (!$bundle) {
      $entity->field_torneo = array();
    }
    else {
      $entity->field_torneo['und'][0]['bundles'] = $bundle;
      $entity->field_torneo['und'][0]['target_id'] = $lpck_id;
    }
    
    // We need to disable pathauto in order to keep the D5 urls
    $entity->path['pathauto'] = 0;
    
    /************************************************************
     * WARNING: This line can make a big performance impact when the migration runs
     */
    // Validate the final url against the production site
    $this->validateUrl($entity);
    
    /*************************************************************/
     
    return;
  }

}

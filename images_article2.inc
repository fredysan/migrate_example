<?php

/**
 * Description of files
 *
 * @author fredy
 */

class CaracolFilesImagesArticle2Migration extends CaracolFilesMigration {
  
  public function __construct($arguments) {
    parent::__construct($arguments);
  }
  
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('files', 'f')
             ->fields('f');
    $query->innerJoin('content_field_img_principal', 'ip', 'ip.field_img_principal_fid = f.fid');
    // $query->condition('f.nid', array(87458), 'IN');
    return $query;
  }
  
}
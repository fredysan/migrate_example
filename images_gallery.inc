<?php

/**
 * Description of files
 *
 * @author fredy
 */


class CaracolFilesImagesGalleryMigration extends CaracolFilesMigration {
  
  public function __construct($arguments) {
    parent::__construct($arguments);
  }
  
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('files', 'f')
             ->fields('f');
    $query->innerJoin('content_field_imagenes', 'im', 'im.field_imagenes_fid = f.fid');
    // $query->condition('im.nid', array(279588, 93743), 'IN');
    return $query;
  }
}
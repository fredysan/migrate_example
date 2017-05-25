<?php

/**
 * Description of files
 *
 * @author fredy
 */

class CaracolFilesImagesMigration extends CaracolFilesMigration {
  
  public function __construct($arguments) {
    parent::__construct($arguments);
  }
  
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('files', 'f')
             ->fields('f');
    $query->innerJoin('content_field_imagen_principal', 'ip', 'ip.field_imagen_principal_fid = f.fid');
    // $query->condition('f.nid', array(335895), 'IN');
    return $query;
  }
  
}
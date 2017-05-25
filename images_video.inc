<?php

/**
 * Description of files
 *
 * @author fredy
 */


class CaracolFilesImagesVideoMigration extends CaracolFilesMigration {
  
  public function __construct($arguments) {
    parent::__construct($arguments);
  }
  
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('files', 'f')
             ->fields('f');
    $query->innerJoin('content_field_img_video', 'im', 'im.field_img_video_fid = f.fid');
    // $query->condition('im.nid', array(155783, 326081), 'IN');
    return $query;
  }
}
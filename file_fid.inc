<?php

/**
 * Se sobreescribió la clase MigrateFileFid para evitar que al hacer un
 * rollback de las galerías se borraran las imágenes vinculadas
 *
 * @author fredy
 */
class CaracolMigrateFileFid extends MigrateFileFid {
  
  public function __construct($arguments = array(), $default_file = NULL) {
    parent::__construct($arguments, $default_file);
    $this->preserveFiles = TRUE;
  }
}

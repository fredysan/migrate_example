<?php

/**
 * Common mappings for the Drupal 5 node migrations.
 */
abstract class CaracolNodeMigration extends DrupalNode5Migration {
  
  // Set this variable to TRUE if want to validate URLs againt the D5 production site
  public $validate_urls = FALSE;
  
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
  
  
  /**
   * Validates new nodes urls against the D5 production site
   */
  public function validateUrl($entity) {
    if (!$this->validate_urls) {
      return;
    }
      
    // Validar la existencia de la URL final en el sitio de golcaracol
    if (isset($entity->path['alias'])) {
      $file = 'http://gol.caracoltv.com/' . $entity->path['alias'];
      $file_headers = @get_headers($file);
      if(!$file_headers || $file_headers[0] == 'HTTP/1.1 404 Not Found') {
        $this->saveMessage(t('404 on !file', array('!file' => $file)));
      }
    }
    else {
      $this->saveMessage(t('Undefined path'), MigrationBase::MESSAGE_INFORMATIONAL);
    }
  }

  
  /**
   *  LPCK Mapping by section name
   */
  function getLpckBundle($value) {
    $d7_tid = $value['und'][0]['target_id'];
    $lpck_map = array(
      8 => 'torneo-special',
      1889 => 'torneo-special',
      12 => 'ligas-y-torneos',
      11 => 'ligas-y-torneos',
      13 => 'ligas-y-torneos',
      14 => 'ligas-y-torneos',
      15 => 'ligas-y-torneos',
      16 => 'ligas-y-torneos',
      17 => 'ligas-y-torneos',
      18 => 'ligas-y-torneos',
      19 => 'ligas-y-torneos',
      20 => 'ligas-y-torneos',
      21 => 'la-seleccion',
      22 => 'la-seleccion',
      23 => 'la-seleccion',
      24 => 'la-seleccion',
      25 => 'secciones',
      26 => 'secciones',
      27 => 'secciones',
      10 => 'especiales-a-b',
      9 => 'especiales-a-b',
    );
    
    $default_bundle = 'secciones';
    return isset($lpck_map[$d7_tid]) ? $lpck_map[$d7_tid] : $default_bundle;
  }
  
  /**
   * LPCK Mapping by lpck id
   */
  function getLpckId($value) {
    $d7_tid = $value['und'][0]['target_id'];
    $lpck_map = array(
      8 => 3,
      1889 => 5,
      12 => 37,
      11 => 38,
      13 => 39,
      14 => 40,
      15 => 41,
      16 => 42,
      17 => 43,
      18 => 44,
      19 => 45,
      20 => 46,
      21 => 47,
      22 => 48,
      23 => 49,
      24 => 50,
      25 => 51,
      26 => 52,
      27 => 53,
      10 => 54,
      9 => 55,
    );
    
    $default_lpid = 63;
    return isset($lpck_map[$d7_tid]) ? $lpck_map[$d7_tid] : $default_lpid;
  }

}
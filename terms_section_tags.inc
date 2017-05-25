<?php

/**
 * Description of drupal_term5_migration_sections
 *
 * @author fredy
 */
class CaracolTermsSectionTagsMigration extends CaracolTermMigration {
  
  function __construct(array $arguments) {
    parent::__construct($arguments);
  }
  
  function query() {
    $query = parent::query();
    
    // Estos ID de D5 corresponden a LPCKs en D7 y seran migrados por separado
    // Los demás serán migrados como tags
    $lpck_d7 = array(
      141202,
      143801,
      143804,
      143803,
      20517,
      20516,
      20512,
      73947,
      117692,
      20511,
      20514,
      117662,
      103485,
      117663,
      117665,
      126187,
    );
    
    $query->condition('td.tid', $lpck_d7, 'NOT IN');
    return $query;
  }
}
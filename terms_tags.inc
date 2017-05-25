<?php

/**
 * Tag terms will be migrated using the default d2d behavior
 *
 * @author fredy
 */
class CaracolTermsTagsMigration extends CaracolTermMigration {

  function __construct(array $arguments) {
    parent::__construct($arguments);
  }

  function query() {
    $query = parent::query();
    
    $query->innerJoin('term_node', 'tn', 'tn.tid = td.tid');
    // $query->condition('tn.nid', array('335895'), 'IN');
    return $query;
  }
  
}

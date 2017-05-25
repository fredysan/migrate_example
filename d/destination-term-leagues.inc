<?php

/**
 * MigrateDestinationTermLeagues overrides the MigrateDestinationTerm class
 * in order to take control over the destination term ids
 *
 * @author fredy
 */

Class MigrateDestinationTermLeagues extends MigrateDestinationTerm {
  
  public function __construct($bundle, array $options = array()) {
    parent::__construct($bundle, $options);
  }
  
  public function import(stdClass $term, stdClass $row) {
    // LPCK map
    $map = array(
      143801 => 17,
      143804 => 20,
      143803 => 13,
      20517 => 18,  // Liga BBVA
      20516 => 11,
      20512 => 19,
      73947 => 12,
      117692 => 16,
      20511 => 14,
      20514 => 15
    );
    
    $term = taxonomy_term_load($map[$row->tid]);
    
    if (isset($term->tid)) {
      $updating = TRUE;
    }
    else {
      $updating = FALSE;
    }

    // Validate field data prior to saving.
    MigrateDestinationEntity::fieldAttachValidate('taxonomy_term', $term);

    migrate_instrument_start('taxonomy_term_save');
    
    // We don't need to save new terms because these terms already exists in D7
    // $status = taxonomy_term_save($term);
    
    migrate_instrument_stop('taxonomy_term_save');
    $this->complete($term, $row);
    if (isset($term->tid)) {
      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
      $return = array($term->tid);
    }
    else {
      $return = FALSE;
    }
    return $return;
  }
  
  public function rollback(array $key) {
    // returning TRUE, rollback doesn't delete the mapped terms
    return TRUE;
  }
    
}
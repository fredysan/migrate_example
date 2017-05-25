<?php

/**
 * Description of drupal_term5_migration_sections
 */
class CaracolTermsSectionLigasMigration extends CaracolTermMigration {

  function __construct(array $arguments) {
    parent::__construct($arguments);

    module_load_include('inc', 'migrate_golcaracol', 'd/destination-term-leagues');
    $this->destination = new MigrateDestinationTermLeagues($this->destinationVocabulary);
  }

  /*
   * Get the LPCK sections based on the term ids
   */
  function query() {
    // LPCK Section ids
    $lpck_d7 = array(
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
    );

    $query = Database::getConnection('default', $this->sourceConnection)
        ->select('term_data', 'td')
        ->fields('td', array('tid', 'name', 'description', 'weight'))
        ->condition('vid', explode(',', $this->sourceVocabulary), 'IN')
        ->condition('td.tid', $lpck_d7, 'IN')
        ->distinct();
    return $query;
  }

  public function prepareRow($row) {
    // We overrided this method just to avoid the default behavior
  }
  
  /**
   * Implementation of Migration::createStub().
   *
   * When a new node is saved and it references an unmapped term then
   * a new Stub term is created
   */
  protected function createStub($migration, $source_key) {
    // Fixed Stub term id
    return array(116);
  }
}

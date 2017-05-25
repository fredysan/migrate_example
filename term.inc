<?php

/**
 * Common mappings for the Drupal 5 node migrations.
 */
abstract class CaracolTermMigration extends DrupalTerm5Migration {

  public $nodes;

  public function __construct(array $arguments) {
  	// Special node ids that correspond to LPCKs
    $this->nodes = array(155783, 326081, 277685, 335813, 258349, 325819, 279588, 93743, 225142, 335895, 335904);

    parent::__construct($arguments);
  }

}

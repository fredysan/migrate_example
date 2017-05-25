<?php

/**
 * @file migrate_d2d_example.migrate.inc
 */
/**
 * This is example code for a Drupal 6 to Drupal 7 migration. This won't actually
 * work without defining the referenced vocabularies, content types, and fields
 * on each side.
 */

/**
 * Implements hook_migrate_api().
 */
function migrate_golcaracol_migrate_api() {
  /**
   * Declare the api version and migration group.
   */
  $api = array(
    'api' => 2,
    'groups' => array(
      'caracol' => array(
        'title' => t('Drupal 5 to Drupal 7'),
      ),
    ),
  );

  $common_arguments = array(
    'source_connection' => 'd5',
    'source_version' => 5,
    'group_name' => 'caracol',
  );
  
  $image_arguments = array(
    'images' => array(
      'description' => t('Image migration'),
      'class_name' => 'CaracolFilesImagesMigration',
      'source_dir' => 'public://',
      // 'source_dir' => 'http://gol.caracoltv.com/sites/golcaracol.com/files/',
    ),
    'images2' => array(
      'description' => t('Image migration'),
      'class_name' => 'CaracolFilesImagesArticle2Migration',
      'source_dir' => 'public://',
      // 'source_dir' => 'http://gol.caracoltv.com/sites/golcaracol.com/files/',
    ),
    'gallery_images' => array(
      'description' => t('Gallery migration'),
      'class_name' => 'CaracolFilesImagesGalleryMigration',
      'source_dir' => 'public://',
      // 'source_dir' => 'http://gol.caracoltv.com/sites/golcaracol.com/files/',
    ),
    'video_images' => array(
      'description' => t('Video images migration'),
      'class_name' => 'CaracolFilesImagesVideoMigration',
      'source_dir' => 'public://',
      // 'source_dir' => 'http://gol.caracoltv.com/sites/golcaracol.com/files/',
    ),
  );
  
  $common_image_arguments = $common_arguments + array(
    
  );
  
  foreach ($image_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_image_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }

  // For vocabulary migrations, source_vocabulary and destination_vocabulary are
  // required arguments. Note that in Drupal 5 vocabularies did not have machine
  // names, so we use the vocabulary ID to uniquely identify them.
  $vocabulary_arguments = array(
    'tags' => array(
      'description' => t('Tags'),
      'source_vocabulary' => '54', // D5 Vocabulary ID
      'destination_vocabulary' => 'tags',
      'class_name' => 'CaracolTermsTagsMigration',
    ),
    'section_tags' => array(
      'description' => t('Section Tags'),
      'source_vocabulary' => '53', // D5 Vocabulary ID
      'destination_vocabulary' => 'tags',
      'class_name' => 'CaracolTermsSectionTagsMigration',
      'dependencies' => array('tags'),
    ),
    'section_ligas' => array(
      'description' => t('Section Tags'),
      'source_vocabulary' => '53', // D5 Vocabulary ID
      'destination_vocabulary' => 'lpck_ligas_torneos',
      'class_name' => 'CaracolTermsSectionLigasMigration',
    ),
  );

  $common_vocabulary_arguments = $common_arguments + array(
    // 'class_name' => 'DrupalTerm5MigrationSections',
  );

  foreach ($vocabulary_arguments as $migration_name => $arguments) {
    $arguments += $common_vocabulary_arguments;
    $api['migrations'][$migration_name] = $arguments;
  }

  // Node migrations - each has its own class derived from the migrate_d2d class,
  // specifying its particular field mappings and transformations. source_type
  // and destination_type are required arguments.
  $node_arguments = array(
    'article' => array(
      'class_name' => 'CaracolArticleMigration',
      'description' => t('Migration of article nodes from Drupal 5'),
      'source_type' => 'ccnota',
      'destination_type' => 'article',
      'dependencies' => array('tags', 'section_ligas', 'images'),
    ),
    /*'article_related' => array(
      'class_name' => 'CaracolArticleRelatedMigration',
      'description' => t('Update article nodes from Drupal 5'),
      'source_type' => 'ccnota',
      'destination_type' => 'article',
      'dependencies' => array('article'),
    ),*/
    'gallery' => array(
      'class_name' => 'CaracolGalleryMigration',
      'description' => t('Migration of gallery nodes from Drupal 5'),
      'source_type' => 'ccgaleria',
      'destination_type' => 'gallery',
      'dependencies' => array('tags', 'section_ligas', 'gallery_images'),
    ),
    'video' => array(
      'class_name' => 'CaracolVideoMigration',
      'description' => t('Migration of video nodes from Drupal 5'),
      'source_type' => 'ccvideo',
      'destination_type' => 'video',
      'dependencies' => array('tags', 'section_ligas', 'images'),
    ),
    'video_ooyala' => array(
      'class_name' => 'CaracolVideoOoyalaMigration',
      'description' => t('Migration of Ooyala video nodes from Drupal 5'),
      'source_type' => 'ccvideo',
      'destination_type' => 'video',
      'dependencies' => array('tags', 'section_ligas', 'video_images'),
    ),
    'survey' => array(
      'class_name' => 'CaracolSubveyMigration',
      'description' => t('Migration of Survey nodes from Drupal 5'),
      'source_type' => 'ccencuesta',
      'destination_type' => 'encuesta',
      'dependencies' => array('section_ligas'),
    ),
  );

  $common_node_arguments = $common_arguments + array(
    'format_mappings' => array(
      '1' => 'full_html',
      '2' => 'full_html',
      '3' => 'full_html',
    ),
  );
  
  $common_node_arguments = $common_arguments;
  
  foreach ($node_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }
  
  return $api;
}

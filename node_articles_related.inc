<?php

class CaracolArticleRelatedMigration extends CaracolNodeMigration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $umd = array(
      'title',
      'uid',
      'created',
      'changed',
      'status',
      'promote',
      'sticky',
      'revision',
      'log',
      'language',
      'tnid',
      'translate',
      'revision_uid',
      'is_new',
      'body',
      'body:summary',
      'body:format',
      'body:language',
      'field_advertising_section',
      'field_advertising_section:source_type',
      'field_advertising_section:create_term',
      'field_advertising_section:ignore_case',
      'field_lead',
      'field_main_image',
      'field_main_image:file_class',
      'field_main_image:preserve_files',
      'field_main_image:destination_dir',
      'field_main_image:destination_file',
      'field_main_image:file_replace',
      'field_main_image:source_dir',
      'field_main_image:urlencode',
      'field_main_image:alt',
      'field_main_image:title',
      'field_section',
      'field_section:source_type',
      'field_section:create_term',
      'field_section:ignore_case',
      'field_section_team',
      'field_section_team:source_type',
      'field_section_team:create_term',
      'field_section_team:ignore_case',
      'field_social_networks',
      'field_special_image',
      'field_special_image:file_class',
      'field_special_image:preserve_files',
      'field_special_image:destination_dir',
      'field_special_image:destination_file',
      'field_special_image:file_replace',
      'field_special_image:source_dir',
      'field_special_image:urlencode',
      'field_special_image:alt',
      'field_special_image:title',
      'field_tags',
      'field_tags:source_type',
      'field_tags:create_term',
      'field_tags:ignore_case',
      'field_torneo',
      'field_advertorial',
      'path',
      'metatag_title',
      'metatag_description',
      'metatag_abstract',
      'metatag_keywords',
      'metatag_robots',
      'metatag_news_keywords',
      'metatag_standout',
      'metatag_generator',
      'metatag_rights',
      'metatag_image_src',
      'metatag_canonical',
      'metatag_shortlink',
      'metatag_publisher',
      'metatag_author',
      'metatag_original-source',
      'metatag_revisit-after',
      'metatag_content-language',
      'metatag_og:site_name',
      'metatag_og:type',
      'metatag_og:url',
      'metatag_og:title',
      'metatag_og:determiner',
      'metatag_og:description',
      'metatag_og:updated_time',
      'metatag_og:see_also',
      'metatag_og:image',
      'metatag_og:image:secure_url',
      'metatag_og:image:type',
      'metatag_og:image:width',
      'metatag_og:image:height',
      'metatag_og:latitude',
      'metatag_og:longitude',
      'metatag_og:street-address',
      'metatag_og:locality',
      'metatag_og:region',
      'metatag_og:postal-code',
      'metatag_og:country-name',
      'metatag_og:email',
      'metatag_og:phone_number',
      'metatag_og:fax_number',
      'metatag_og:locale',
      'metatag_og:locale:alternate',
      'metatag_article:author',
      'metatag_article:publisher',
      'metatag_article:section',
      'metatag_article:tag',
      'metatag_article:published_time',
      'metatag_article:modified_time',
      'metatag_article:expiration_time',
      'metatag_profile:first_name',
      'metatag_profile:last_name',
      'metatag_profile:username',
      'metatag_profile:gender',
      'metatag_og:audio',
      'metatag_og:audio:secure_url',
      'metatag_og:audio:type',
      'metatag_book:author',
      'metatag_book:isbn',
      'metatag_book:release_date',
      'metatag_book:tag',
      'metatag_og:video',
      'metatag_og:video:secure_url',
      'metatag_og:video:width',
      'metatag_og:video:height',
      'metatag_og:video:type',
      'metatag_video:actor',
      'metatag_video:actor:role',
      'metatag_video:director',
      'metatag_video:writer',
      'metatag_video:duration',
      'metatag_video:release_date',
      'metatag_video:tag',
      'metatag_video:series',
      'comment',
      'totalcount',
      'daycount',
      'timestamp',
    );

    $ums = array(
      'title',
      'body',
      'format',
      'teaser',
      'uid',
      'created',
      'changed',
      'status',
      'promote',
      'sticky',
      'revision',
      'log',
      'language',
      'tnid',
      'revision_uid',
      'field_autor_de_sp',
      'field_colombianos_champions_lea',
      'field_colombianos_champions_lea:title',
      'field_colombianos_champions_lea:alt',
      'field_concurso_gol',
      'field_desactivar_video',
      'field_equipo_champions',
      'field_equipo_champions_url',
      'field_es_publireportaje',
      'field_imagen_extra',
      'field_imagen_extra:title',
      'field_imagen_extra:alt',
      'field_imagen_extra_0',
      'field_imagen_extra_0:title',
      'field_imagen_extra_0:alt',
      'field_imagen_momentos_colombian',
      'field_imagen_momentos_colombian:title',
      'field_imagen_momentos_colombian:alt',
      'field_imagen_momentos_recordar',
      'field_imagen_momentos_recordar:title',
      'field_imagen_momentos_recordar:alt',
      'field_imagen_principal',
      'field_imagen_principal:title',
      'field_imagen_principal:alt',
      'field_imagen_seleccin_colombia',
      'field_imagen_seleccin_colombia:title',
      'field_imagen_seleccin_colombia:alt',
      'field_imagen_spot_especial',
      'field_imagen_spot_especial:title',
      'field_imagen_spot_especial:alt',
      'field_img_300120',
      'field_img_300120:title',
      'field_img_300120:alt',
      'field_img_300300',
      'field_img_300300:title',
      'field_img_300300:alt',
      'field_img_6060',
      'field_img_6060:title',
      'field_img_6060:alt',
      'field_img_destacado_liga_gol_ca',
      'field_img_destacado_liga_gol_ca:title',
      'field_img_destacado_liga_gol_ca:alt',
      'field_img_principal',
      'field_img_principal:title',
      'field_img_principal:alt',
      'field_medios_asociados',
      'field_relacionados',
      'field_tomado_de_sp',
      'field_url_perfil_colaborador_sp',
      'field_url_perfil_colaborador_sp:title',
      'field_url_perfil_colaborador_sp:attributes',
      'field_url_soyperiodista',
      'field_url_soyperiodista:title',
      'field_url_soyperiodista:attributes',
      'field_video_ooyala',
      '53',
      '93',
      '54',
      'path',
      'vid',
      'comment',
      'moderate',
    );

    $this->addUnmigratedDestinations($umd);
    $this->addUnmigratedSources($ums);
    
    $this->addFieldMapping('nid', 'nid')
        ->sourceMigration('article');
    
    $this->addFieldMapping('field_related_content', 'field_relacionado_destacado')
      ->sourceMigration('article');
    
  }

  /**
   * Se sobreescribió el query para eliminar joins que no se necesitan
   * 
   * @return type
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
        ->select('node', 'n')
        ->fields('n', array('nid', 'vid', 'title',
          'uid', 'status', 'created', 'changed', 'comment', 'promote',
          'moderate', 'sticky'))
        ->condition('n.type', $this->sourceType)
        ->orderBy('n.changed');
    $query->innerJoin('node_revisions', 'nr', 'n.vid=nr.vid');
    $query->innerJoin('content_field_relacionado_destacado', 'rd', 'rd.field_relacionado_destacado_nid != 0 AND n.nid = rd.nid');
    
    $query->condition('n.nid', array(225142, 235396), 'IN');
    return $query;
  }

  /**
   * Este metodo se ejecuta despues de obtener la informacion desde D5
   * y antes de preparar el objeto que va a ser guardado en el destino
   * 
   * @param type $row
   */
  function prepareRow($row) {
    parent::prepareRow($row);
  }

  /**
   * Este método se llama justo antes de guardar el nodo
   * 
   * @param type $entity
   * @param type $source_row
   * @return type
   */
  public function prepare($entity, $source_row) {
    return;
  }

}

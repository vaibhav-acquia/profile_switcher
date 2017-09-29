<?php
/**
 * @file Contains the code for the profile_switcher drush commands.
 */
/**
 * Implements hook_drush_command().
 */
function profile_switcher_drush_command() {
  $items = array();
  $items['switch-profile'] = [
    'description' => 'Switch Drupal profile in a installed site',
    'arguments' => [
      'profile_name' => 'The profile to activate',
      'profile_to_delete' => 'The profile to disable',
    ],
    'drupal dependencies' => ['profile_switcher'],
    'aliases' => ['switch:profile'],
  ];
  return $items;
}

/**
 * Call back function drush_custom_drush_command_()
 */
function drush_profile_switcher_switch_profile($profile_name = '', $profile_to_remove = '') {

  $extension_config = \Drupal::configFactory()->getEditable('core.extension');
  $profile = $extension_config->get('profile');
  $profile_name = strVal($profile_name);

  if ($profile_to_remove === $profile || $profile_to_remove === '') {
    drush_print('Removing ' . $profile_to_remove . '.');

    drush_print('Switching to ' . $profile_name . '.');

    $extension_config->set('profile', $profile_name);
    $extension_config->save();
    drupal_flush_all_caches();
  } else {
    drush_print('Trying to switch from wrong profile. Current profile: ' . $profile);
  }
}

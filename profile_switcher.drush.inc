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
 * Call back function drush_custom_drush_command_().
 *
 * @param string $profile_to_install
 *
 */
function drush_profile_switcher_switch_profile($profile_to_install = '') {
  drush_print('Current profile: ' . \Drupal::installProfile());

  \Drupal::service('profile_switcher.profile_switcher')->switchProfile($profile_to_install);

  drush_print('Profile changed to: ' . \Drupal::installProfile());
}

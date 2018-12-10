<?php

namespace Drupal\profile_switcher\Commands;

use Drush\Commands\DrushCommands;

/**
 * A Drush commandfile for Profile Switcher module.
 */
class ProfileSwitcherCommands extends DrushCommands {

  /**
   * Switch Drupal profile in a installed site
   *
   * @param string $profile_to_install
   *   The profile to activate.
   *
   * @command switch:profile
   * @aliases sp,switch-profile
   */
  public function profile($profile_to_install) {
    $profile_to_remove = \Drupal::installProfile();

    $this->output()->writeln('Current profile: ' . $profile_to_remove);
    $this->output()->writeln('Switching profile to ' . $profile_to_install . '!');

    \Drupal::service('profile_switcher.profile_switcher')->switchProfile($profile_to_install);

    $this->output()->writeln('Profile changed to: ' . \Drupal::installProfile());
  }

}

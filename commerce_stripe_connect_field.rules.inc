<?php

/**
 * Implementation of hook_rules_event_info()
 */
function commerce_stripe_connect_field_rules_event_info() {
  return array(
    'commerce_stripe_connect_field_alter_api_key' => array(
      'label' => t('Swap sitewide Stripe API key for user\'s Stripe Connect Access Token'),
      'group' => 'Commerce Stripe Connect',
      'variables' => array(
        'apk_key' => array('type' => 'user', 'label' => t('The current logged in user.')),
      ),
    ),
    'commerce_stripe_connect_field_alter_charge' => array(
      'label' => t('Alter the Stripe Connect charge to add application fees'),
      'group' => 'Commerce Stripe Connect',
      'variables' => array(
        'charge' => array('type' => 'user', 'label' => t('The current logged in user.')),
      ),
    ),
  );
}

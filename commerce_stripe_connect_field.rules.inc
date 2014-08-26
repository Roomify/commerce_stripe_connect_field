<?php

/**
 * Implementation of hook_rules_action_info()
 */
function commerce_stripe_connect_field_rules_action_info() {
  return array(
    'commerce_stripe_connect_field_alter_api_key' => array(
      'label' => t('Swap sitewide Stripe API key for user\'s Stripe Connect Access Token'),
      'group' => 'Commerce Stripe Connect',
      'parameter' => array(
        'api_key' => array('type' => 'text', 'label' => t('The Stripe Connect Access Token. Defaults to sitewide API key.')),
      ),
    ),
    'commerce_stripe_connect_field_alter_charge' => array(
      'label' => t('Alter the Stripe Connect charge to add application fees'),
      'group' => 'Commerce Stripe Connect',
      'parameter' => array(
        'charge' => array('type' => 'list', 'label' => t('An array containing the charge parameters..')),
      ),
    ),
  );
}

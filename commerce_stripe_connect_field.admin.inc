<?php

/**
 * @file
 * Commerce Stripe Connect Field module admin settings.
 */

/**
 * Return the Commerce Stripe Connect Field global settings form.
 */
function commerce_stripe_connect_field_admin_settings() {
  $form['commerce_stripe_connect_field_secret_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret key'),
    '#default_value' => variable_get('commerce_stripe_connect_field_secret_key'),
    '#description' => t("Test or Live Stripe secret key"),
    '#required' => TRUE,
  );
  $form['commerce_stripe_connect_field_public_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Publishable key'),
    '#default_value' => variable_get('commerce_stripe_connect_field_public_key'),
    '#description' => t("Test or Live Stripe publishable key"),
    '#required' => TRUE,
  );
  $form['commerce_stripe_connect_field_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client id'),
    '#default_value' => variable_get('commerce_stripe_connect_field_client_id'),
    '#description' => t("Development or Production app client_id"),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
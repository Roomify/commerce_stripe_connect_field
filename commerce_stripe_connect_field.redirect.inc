<?php
/**
 * @file
 * Saves user Stripe Access Token when redirected by successful Stripe signup page.
 */
function commerce_stripe_connect_field_process_redirect() {
  if (isset($_GET['code'])) {
    $code = $_GET['code'];
    $client_secret = variable_get('commerce_stripe_connect_field_secret_key');
    $data = 'client_secret=' . $client_secret . '&code=' . $code . '&grant_type=authorization_code';
    $options = array(
                    'method' => 'POST',
                    'data' => $data,
            );
    $result = drupal_http_request('https://connect.stripe.com/oauth/token', $options);
    $json = json_decode($result->data);

    // Handle error response.
    if (!empty($json->error)) {
      $stripe_message = array(
        'message' => 'There was an error connecting your Stripe account.' . $json->error,
        'severity' => 'error',
      );
      watchdog('commerce stripe connect field', $json->error_description, array(), WATCHDOG_ERROR);
    }
    else {
      // Load current user so that we can run additional security checks
      global $user;

      // Save to either node or user.
      if ($_COOKIE['Drupal_visitor_entity_type'] == 'node') {
        $edit = node_load($_COOKIE['Drupal_visitor_eid']);

        // Let's run an additonal security check to make sure the user has update access to the nid set in the cookie.
        if (node_access('update', $edit, $user)) {
          $edit->field_stripe_connect[LANGUAGE_NONE][0]['stripe_connect_access_token'] = $json->access_token;
          $edit->field_stripe_connect[LANGUAGE_NONE][0]['stripe_connect_publishable_key'] = $json->stripe_publishable_key;
          $edit->field_stripe_connect[LANGUAGE_NONE][0]['stripe_connect_user_id'] = $json->stripe_user_id;
          // Field attach update.
          field_attach_update('node', $edit);

          // Re-set cache for this node.
          entity_load('node', array($edit->nid), array(), TRUE);
        }
        else {
          $stripe_message = array(
          'message' => 'There was a problem updating you Stripe Connect info.',
          'severity' => 'error',
          );
        }
      }
      elseif ($_COOKIE['Drupal_visitor_entity_type'] == 'user') {
        $edit = user_load($user->uid);
        $edit->field_stripe_connect[LANGUAGE_NONE][0]['stripe_connect_access_token'] = $json->access_token;
        $edit->field_stripe_connect[LANGUAGE_NONE][0]['stripe_connect_publishable_key'] = $json->stripe_publishable_key;
        $edit->field_stripe_connect[LANGUAGE_NONE][0]['stripe_connect_user_id'] = $json->stripe_user_id;
        // Field attach update.
        field_attach_update('user', $edit);

        // Re-set cache for this user.
        entity_load('user', array($edit->uid), array(), TRUE);
      }

      $stripe_message = array(
      'message' => 'Payments are now connected through Stripe Connect.',
      'severity' => 'status',
      );
    }
  }
  // Let's show more specific messages to user based on error type returned.
  elseif ((isset($_GET['error'])) && ($_GET['error'] == 'access_denied')) {
    $stripe_message = array(
    'message' => 'You denied access to your Stripe account.',
    'severity' => 'warning',
    );
  }
  else {
    $stripe_message = array(
    'message' => 'There was an error connecting your Stripe account.',
    'severity' => 'error',
    );
  }
  drupal_set_message($stripe_message['message'], $stripe_message['severity']);

  // We use the set cookie value instead of a Stripe redirect parameter since our referring pages are dynamic. See https://stripe.com/docs/connect/reference.
  drupal_goto(urldecode($_COOKIE['Drupal_visitor_redirect']));
}

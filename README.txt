COMMERCE STRIPE CONNECT FIELD --------------
This adds Stripe Connect (https://stripe.com/connect) functionality to Drupal Commerce so that
site users can sell Commerce products with their own credit card merchant account. Stripe Connect 
vendor API tokens and keys are stored as either node or user fields.

This module also provides a new 'Stripe Connect' payment method for user by Drupal Commerce.
Specific checkout rules pertaining to which vendor tokens and other customizations can
be made through a custom Rule.


Installation ------------

Download the Stipe PHP library found here:
https://github.com/stripe/stripe-php and extract it to
sites/all/libraries/stripe-php, so that Stripe.php is found under
sites/all/libraries/stripe-php/lib

Copy this to your module directory and then enable on the admin modules
page.  Enter your Stripe Secret Key, Publishable Key, and app Client ID at
admin/config/services/stripefield. 
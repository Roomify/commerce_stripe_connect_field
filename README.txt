COMMERCE STRIPE CONNECT FIELD --------------
This adds Stripe Connect (https://stripe.com/connect) functionality to Drupal Commerce so that
site users can sell Commerce products with their own credit card merchant account. Stripe Connect
vendor API tokens and keys are stored as either node or user fields.

Installation ------------

Copy this to your module directory and then enable on the admin modules
page.  Enter your Stripe Secret Key, Publishable Key, and app Client ID at
admin/config/services/stripefield.

NB: When adding a Stripe Connect Field to a node or user, it must have the machine name field_stripe_connect

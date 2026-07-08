#include "jwg_features.h"
#include "jwg_wifi_led.h"

#include <Arduino.h>



#if JWG_WIFI_STATUS_LED

static uint32_t connected_time = 0;
static bool waiting_to_dim = false;

void jwg_wifi_led_init()
{
    ledcSetup(JWG_WIFI_LED_CHANNEL, JWG_WIFI_LED_FREQ, JWG_WIFI_LED_BITS);
    ledcAttachPin(JWG_WIFI_STATUS_LED_PIN, JWG_WIFI_LED_CHANNEL);
    ledcWrite(JWG_WIFI_LED_CHANNEL, JWG_WIFI_LED_OFF);
}

void jwg_wifi_led_connected()
{
    ledcWrite(JWG_WIFI_LED_CHANNEL, JWG_WIFI_LED_FULL);
    connected_time = millis();
    waiting_to_dim = true;
}

void jwg_wifi_led_disconnected()
{
    waiting_to_dim = false;
    ledcWrite(JWG_WIFI_LED_CHANNEL, JWG_WIFI_LED_OFF);
}

void jwg_wifi_led_loop()
{
    if(waiting_to_dim && millis() - connected_time >= JWG_WIFI_STATUS_LED_DELAY) {
       waiting_to_dim = false;
       ledcWrite(JWG_WIFI_LED_CHANNEL, JWG_WIFI_STATUS_LED_DIM);
   }
}

#endif // JWG_WIFI_STATUS_LED

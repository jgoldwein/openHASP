#include "jwg_wifi_led.h"

#include <Arduino.h>

#define JWG_WIFI_LED_PIN       21
#define JWG_WIFI_LED_FULL      0     // active-low LED: 0 = full on
#define JWG_WIFI_LED_DIM       240   // active-low LED: higher = dimmer
#define JWG_WIFI_LED_OFF       255   // active-low LED: 255 = off
#define JWG_WIFI_LED_DELAY_MS  10000
#define JWG_WIFI_LED_FREQ      5000
#define JWG_WIFI_LED_BITS      8
#define JWG_WIFI_LED_CHANNEL   7

static uint32_t connected_time = 0;
static bool waiting_to_dim = false;

void jwg_wifi_led_init()
{
    ledcSetup(JWG_WIFI_LED_CHANNEL,JWG_WIFI_LED_FREQ,JWG_WIFI_LED_BITS);
    ledcAttachPin(JWG_WIFI_LED_PIN, JWG_WIFI_LED_CHANNEL);
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
    if(waiting_to_dim &&
       millis() - connected_time >= JWG_WIFI_LED_DELAY_MS) {
       waiting_to_dim = false;
       ledcWrite(JWG_WIFI_LED_CHANNEL, JWG_WIFI_LED_DIM);
    }
}


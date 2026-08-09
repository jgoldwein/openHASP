#include "jwg_features.h"
#include "jwg_haptic.h"

#if JWG_HAPTIC_FEEDBACK

static bool haptic_active = false;
static uint32_t haptic_off_time = 0;

static void jwg_haptic_start(uint16_t duration_ms)
{
    if(duration_ms == 0) return;

    // Reassert GPIO mode in case another subsystem reconfigured the pin
//    pinMode(JWG_HAPTIC_PIN, OUTPUT);
    digitalWrite(JWG_HAPTIC_PIN, JWG_HAPTIC_ACTIVE_LEVEL);

    haptic_active = true;
    haptic_off_time = millis() + duration_ms;
}

void jwg_haptic_init()
{
    pinMode(JWG_HAPTIC_PIN, OUTPUT);
    digitalWrite(JWG_HAPTIC_PIN, !JWG_HAPTIC_ACTIVE_LEVEL);
}

void jwg_haptic_loop()
{
    if(haptic_active &&
       (int32_t)(millis() - haptic_off_time) >= 0) {
        digitalWrite(JWG_HAPTIC_PIN, !JWG_HAPTIC_ACTIVE_LEVEL);
        haptic_active = false;
    }
}
void jwg_haptic_blip()

{
    pinMode(JWG_HAPTIC_PIN, OUTPUT);
    digitalWrite(JWG_HAPTIC_PIN, !JWG_HAPTIC_ACTIVE_LEVEL);

    delay(40);  // allow haptic hardware/power to stabilize after deep-sleep wake

    digitalWrite(JWG_HAPTIC_PIN, JWG_HAPTIC_ACTIVE_LEVEL);
    delay(25);
    digitalWrite(JWG_HAPTIC_PIN, !JWG_HAPTIC_ACTIVE_LEVEL);

    haptic_active = false;
}


void jwg_haptic_click()
{
    jwg_haptic_start(JWG_HAPTIC_CLICK_MS);
}

void jwg_haptic_long()
{
    jwg_haptic_start(JWG_HAPTIC_LONG_MS);
}

void jwg_haptic_double()
{
    pinMode(JWG_HAPTIC_PIN, OUTPUT);

    digitalWrite(JWG_HAPTIC_PIN, JWG_HAPTIC_ACTIVE_LEVEL);
    delay(JWG_HAPTIC_CLICK_MS);

    digitalWrite(JWG_HAPTIC_PIN, !JWG_HAPTIC_ACTIVE_LEVEL);
    delay(JWG_HAPTIC_PAUSE_MS);

    digitalWrite(JWG_HAPTIC_PIN, JWG_HAPTIC_ACTIVE_LEVEL);
    delay(JWG_HAPTIC_CLICK_MS);

    digitalWrite(JWG_HAPTIC_PIN, !JWG_HAPTIC_ACTIVE_LEVEL);

    haptic_active = false;
}
#else

void jwg_haptic_init() {}
void jwg_haptic_loop() {}
void jwg_haptic_click() {}
void jwg_haptic_blip() {}
void jwg_haptic_long() {}
void jwg_haptic_double() {}

#endif

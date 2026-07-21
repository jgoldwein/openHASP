#include "jwg_features.h"
#include "jwg_haptic.h"

#if JWG_HAPTIC_FEEDBACK

static bool haptic_active = false;
static uint32_t haptic_off_time = 0;

static void jwg_haptic_start(uint16_t duration_ms)
{
   digitalWrite(JWG_HAPTIC_PIN, HIGH);
   haptic_active = true;
   haptic_off_time = millis() + duration_ms;
}

void jwg_haptic_init()
{
   pinMode(JWG_HAPTIC_PIN, OUTPUT);
   digitalWrite(JWG_HAPTIC_PIN, LOW);
}

void jwg_haptic_loop()
{
   if(haptic_active && millis() >= haptic_off_time) {
   digitalWrite(JWG_HAPTIC_PIN, LOW);
   haptic_active = false;
   }
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
   // Placeholder for now
   jwg_haptic_start(JWG_HAPTIC_CLICK_MS);
}

#else

void jwg_haptic_init() {}
void jwg_haptic_loop() {}
void jwg_haptic_click() {}
void jwg_haptic_long() {}
void jwg_haptic_double() {}

#endif

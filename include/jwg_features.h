// include/jwg_features.h
//
#pragma once

// -----------------------------------------------------------------------------
// JWG Feature Configuration
// -----------------------------------------------------------------------------
#define JWG_FEATURE_VERSION            "1.0"
//
// Hardware
#define JWG_XIAO_ESP32S3             	1

// Fast Boot
#define JWG_FAST_BOOT			1

// Firmware Update Settings
#define JWG_WAKE_DISPLAY_DURING_OTA 	1

// Motion / Power
#define JWG_MOTION_PIN                  1

#define JWG_MOTION_SENSOR            	1
#define JWG_100MS_SLEEP_CHECK        	1
#define JWG_BACKLIGHT_DIMMING        	1
#define JWG_LOW_POWER_MODE           	0


#define JWG_BRIGHT_ACTIVE              255
#define JWG_BRIGHT_SHORT               40
#define JWG_BRIGHT_LONG                1

// Idle Timers (seconds)
#define JWG_IDLE_SHORT_SEC         10
#define JWG_IDLE_LONG_SEC          30    // additional time after short (10 + 30 = 40 s)


// Deep Sleep
#define JWG_DEEP_SLEEP_MODE          1
#define JWG_DEEP_SLEEP_AFTER_SEC     120   // 10 minutes

// Display
#define JWG_DEFAULT_TOUCH_CALIBRATION	1
#define JWG_2_8_INCH_TFT_DISPLAY	1 // Screen Power inversion flag for 2.8 inch TFT screen (see hasp.cpp)
////////////////////////////////////////////
// Subject to later change
#define JWG_CUSTOM_ONLINE_MSG        	1
////////////////////////////////////////////
#define JWG_DEFAULT_BACKLIGHT        	1
#define JWG_DEFAULT_ONLINE_MESSAGE 	1

#define JWG_TOUCH_CAL_X_MIN            607
#define JWG_TOUCH_CAL_X_MAX            2726
#define JWG_TOUCH_CAL_Y_MIN            415
#define JWG_TOUCH_CAL_Y_MAX            3341
#define JWG_TOUCH_CAL_ROT              0

// Networking
#define JWG_WIFI_FAILOVER            	1

// Debugging
#define JWG_EXTRA_LOGGING            	1

// WiFi Quick Connection Settings
#define JWG_WIFI_PREFER_PRIMARY_ON_BOOT 1
#define JWG_WIFI_RECONNECT_TIMEOUT_SEC  10


// WiFi Status LED
#define JWG_WIFI_STATUS_LED        1
#define JWG_WIFI_STATUS_LED_PIN    21
#define JWG_WIFI_STATUS_LED_DIM    25      // 0-255 (10%)
#define JWG_WIFI_STATUS_LED_DELAY  10000   // milliseconds
#define JWG_WIFI_LED_FULL          0       // active-low
#define JWG_WIFI_LED_OFF           255
#define JWG_WIFI_LED_FREQ          5000
#define JWG_WIFI_LED_BITS          8
#define JWG_WIFI_LED_CHANNEL       7

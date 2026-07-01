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

// Motion / Power
#define JWG_MOTION_SENSOR            	1
#define JWG_100MS_SLEEP_CHECK        	1
#define JWG_BACKLIGHT_DIMMING        	1
#define JWG_LOW_POWER_MODE           	0

// Display
#define JWG_DEFAULT_TOUCH_CALIBRATION	1
#define JWG_CUSTOM_ONLINE_MSG        	1
#define JWG_DEFAULT_BACKLIGHT        	1

// Networking
#define JWG_WIFI_FAILOVER            	1

// Debugging
#define JWG_EXTRA_LOGGING            	1

// WiFi Status LED
#define JWG_WIFI_STATUS_LED        1
#define JWG_WIFI_STATUS_LED_PIN    21
#define JWG_WIFI_STATUS_LED_DIM    25      // 0-255 (10%)
#define JWG_WIFI_STATUS_LED_DELAY  10000   // milliseconds


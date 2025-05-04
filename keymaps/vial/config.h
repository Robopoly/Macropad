#pragma once
#define VIAL_KEYBOARD_UID {0xC2, 0xED, 0x95, 0x5A, 0x64, 0xA4, 0x43, 0x85}
#define NO_ACTION_LAYER

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define VENDOR_ID 0xFEED      // Custom Vendor ID
#define PRODUCT_ID 0x6060     // Custom Product ID

// Encoder
#define ENCODERS_PAD_A { D7 }  
#define ENCODERS_PAD_B { C6 }  
#define ENCODER_RESOLUTION 4

//leds
#define WS2812_DI_PIN F7
#define RGBLED_NUM 4
#define RGBLIGHT_LED_COUNT RGBLED_NUM

#define RGBLIGHT_LIMIT_VAL 80
#define RGBLIGHT_HUE_STEP 5
#define RGBLIGHT_SAT_STEP 5
#define RGBLIGHT_VAL_STEP 5

//oled
#define OLED_DRIVER ssd1306
#define OLED_TRANSPORT i2c
#define OLED_BRIGHTNESS 255
#define OLED_DISPLAY_ADDRESS 0x3C

#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 64

#define I2C1_SCL_PIN D0 // Update with your microcontroller's pin
#define I2C1_SDA_PIN D1 // Update with your microcontroller's pin
// optimisation
#define NO_ACTION_TAPPING   //Can be useful but for now I don't need it

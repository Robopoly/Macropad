#include QMK_KEYBOARD_H
#include "quantum.h"  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A,   KC_B,  KC_C,
        KC_D,   KC_E,   KC_F,
        KC_G,   KC_H,   KC_I
    )
};

// ---------------------rotary encoder---------------------
 void matrix_init_user(void) { setPinInputHigh(D4); }

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
    //                  Encoder 1                            
};
#endif

// Encoder Button Press for Layer Cycling
void matrix_scan_user(void) {
    static bool encoder_pressed = false;
    if (!readPin(D4)) { // Assuming D4 is the encoder button pin
        if (!encoder_pressed) {
            rgblight_toggle();
            encoder_pressed = true;
        }
    } else {
        encoder_pressed = false;
    }
}
//---------------------oled---------------------

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180; 
} 


bool oled_task_user(void) {
    // Define image array
    //Plain bytes, Vertical - 1bit per pixel (image2cpp)
    static const char PROGMEM image[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0x70, 0x30, 0x38, 0x18, 0x18, 0x18, 0x98, 
0xd8, 0x58, 0xd8, 0x98, 0xb8, 0xb0, 0x70, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xf8, 0xfe, 0x0f, 0x63, 0x5c, 0x00, 0xfc, 0xfe, 0x1e, 0xee, 0xf6, 0x36, 0x36, 
0x36, 0x36, 0xf6, 0xee, 0x1c, 0xf9, 0xf3, 0x0e, 0xd8, 0x73, 0x0f, 0xfe, 0xf8, 0x00, 0x00, 0x00, 
0xff, 0x01, 0x01, 0x01, 0x01, 0x03, 0x06, 0x0c, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x01, 0x01, 0x01, 
0xff, 0x00, 0x00, 0x30, 0x8c, 0x04, 0x0c, 0x08, 0xf8, 0x00, 0xe0, 0x38, 0x0c, 0x0c, 0x00, 0x00, 
0x30, 0xe0, 0x30, 0x10, 0x18, 0x90, 0xe0, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xff, 0x01, 0x01, 0x01, 0x01, 0x21, 0x21, 0x21, 0x01, 0x01, 0x01, 0x03, 0x86, 0xfc, 
0x00, 0x00, 0x60, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0xc0, 0x40, 0x60, 0x20, 0x20, 0x60, 0xc0, 
0xfc, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x1f, 0x7f, 0xf0, 0xc6, 0xba, 0x00, 0xff, 0xff, 0xf8, 0x77, 0x6f, 0x6c, 0x6c, 
0x6c, 0xec, 0xef, 0xf7, 0xf8, 0x9f, 0x0f, 0x60, 0xbd, 0xc7, 0xf0, 0x7f, 0x1f, 0x00, 0x00, 0x00, 
0xff, 0x80, 0x80, 0x80, 0x80, 0xff, 0x06, 0x0c, 0x18, 0x0c, 0x06, 0xff, 0x80, 0x80, 0x80, 0x80, 
0xff, 0x00, 0x06, 0x1f, 0x11, 0x19, 0x09, 0x03, 0x07, 0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x00, 
0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x06, 0x0c, 0x08, 0x08, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xff, 0x80, 0x80, 0x80, 0x80, 0xfe, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x01, 0x00, 
0x0c, 0x1e, 0x13, 0x11, 0x19, 0x07, 0x0f, 0x00, 0x03, 0x0f, 0x18, 0x10, 0x10, 0x18, 0x0c, 0x0f, 
0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x06, 0x0f, 0x0f, 0x1f, 0x18, 0x18, 0x18, 0x18, 
0x18, 0x18, 0x1b, 0x1f, 0x1f, 0x0f, 0x0e, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
        oled_write_raw_P(image, sizeof(image));
        return false;

}

#endif    

# Core Vial configurations
VIAL_ENABLE = yes
VIAL_INSECURE = yes           # Optional: Enables unsafe features like live EEPROM updates
DYNAMIC_KEYMAP_ENABLE = yes
EEPROM_ENABLE = yes

# Disable VIA (Vial and VIA are separate systems)
VIA_ENABLE = yes

# Feature Flags (Enable based on your hardware features)
RGBLIGHT_ENABLE = yes         # Enable if you have RGB lighting
ENCODER_ENABLE = yes          # Enable if you have rotary encoders
ENCODER_MAP_ENABLE = yes      # Required if you have custom encoder mappings
OLED_ENABLE = yes             # Enable if you have an OLED display
EXTRAKEY_ENABLE = yes         # Support for extra multimedia keys
	

# Optimization Flags
KEY_OVERRIDE_ENABLE = no		#needed if i remove layers
LTO_ENABLE = yes              # Link-time optimization
EXTRAFLAGS += -flto           # Further LTO-related optimizations
NO_DEBUG = yes                # Disable debug mode
CONSOLE_ENABLE = no          # Disable the console for better performance

# Disabled Features (Unless Required)
MOUSEKEY_ENABLE = no          # Disable mouse emulation
BOOTMAGIC_ENABLE = no         # Disable bootmagic (hold key on boot to reset)
UNICODE_ENABLE = no           # Disable Unicode keymaps

# Additional Compatibility
KEYMAP_INTROSPECTION_ENABLE = yes  # Enables introspection in keymaps (needed for Vial)
# Declarations for RP2040 / Elite-Pi compatability
# Declare the base for conversions
PIN_COMPATIBLE = elite_c
CONVERT_TO = elite_pi
BOOTLOADER = rp2040

SPLIT_KEYBOARD = yes

TRI_LAYER_ENABLE = yes

ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# Enable per-key lighting
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

# Enable audio keys and system control
EXTRAKEY_ENABLE = yes

# Enable link time optimization
# Trade longer compile time for smaller firmware size
# Disable for RP2040
#LTO_ENABLE = yes

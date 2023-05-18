# Declarations for RP2040 / Elite-Pi compatability
# Declare the base for conversions
#PIN_COMPATIBLE = elite_c
CONVERT_TO = elite_pi
#BOOTLOADER = rp2040

# Uncomment for RP2040
SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor

TRI_LAYER_ENABLE = yes

ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

OLED_ENABLE = yes

# Enable per-key lighting
RGB_MATRIX_ENABLE = no # disable for debugging

# Enable audio keys and system control
EXTRAKEY_ENABLE = yes

# Enable link time optimization
# Trade longer compile time for smaller firmware size
# Disable for RP2040
#LTO_ENABLE = yes

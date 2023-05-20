# Enable QMK converter to Elite-Pi
# Defaults:
# MCU := RP2040
# BOARD := QMK_PM2040
# BOOTLOADER := rp2040
# SERIAL_DRIVER ?= vendor
# WS2812_DRIVER ?= vendor
# BACKLIGHT_DRIVER ?= software
# OPT_DEFS += -DUSB_VBUS_PIN=19U
CONVERT_TO = elite_pi

TRI_LAYER_ENABLE = yes

ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

OLED_ENABLE = yes

# Enable per-key lighting
RGB_MATRIX_ENABLE = no # disable for debugging
RGBLIGHT_ENABLE = yes #disable for debugging

# Enable audio keys and system control
EXTRAKEY_ENABLE = yes

# Enable link time optimization
# Trade longer compile time for smaller firmware size
# Disable for RP2040
#LTO_ENABLE = yes

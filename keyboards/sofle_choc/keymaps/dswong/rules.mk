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

# Build options
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
OLED_ENABLE = yes
RGB_MATRIX_ENABLE = no      # Does not work with RP2040
RGBLIGHT_ENABLE = yes
LTO_ENABLE = no             # Disable for RP2040

# QMK feature options
AUTOCORRECT_ENABLE = no		# WIP
COMBO_ENABLE = no		    # WIP
EXTRAKEY_ENABLE = yes       # Enable audio keys and system control
TAP_DANCE_ENABLE = no		# WIP
TRI_LAYER_ENABLE = yes
WPM_ENABLE = yes

# VIA support
VIA_ENABLE = yes
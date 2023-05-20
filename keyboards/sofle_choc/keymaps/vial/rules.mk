# Declare the base for conversions
PIN_COMPATIBLE = elite_c
#CONVERT_TO = elite_pi
BOARD = GENERIC_RP_RP2040
BOOTLOADER = rp2040

# TRI_LAYER_ENABLE = yes

ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

OLED_ENABLE = yes

# Enable per-key lighting
RGB_MATRIX_ENABLE = yes

# Enable audio keys and system control
EXTRAKEY_ENABLE = yes

# Enable link time optimization
# Trade longer compile time for smaller firmware size
# LTO_ENABLE = yes

# Try and save some space
QMK_SETTINGS = no
# TAP_DANCE_ENABLE = no
# COMBO_ENABLE = no
KEY_OVERRIDE_ENABLE = no

# CONSOLE_ENABLE = no
# COMMAND_ENABLE = no
# MOUSEKEY_ENABLE = yes

SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no

AVR_USE_MINIMAL_PRINTF = yes

# Enable use of Vial
# Similar to VIA
# https://get.vial.today/
VIA_ENABLE = yes
VIAL_ENABLE = yes
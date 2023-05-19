May 17, 2023

Encountered a very strange issue when converting a working Elite-C configuration to Elite-Pi (RP2040). The OLED shows a noisy pattern of random pixes, slowly loads the first four lines, then freezes (?) and the keyboard does not work.

Based on this reddit comment (https://www.reddit.com/r/ErgoMechKeyboards/comments/11ly1f1/comment/jbg0lsr/?utm_source=share&utm_medium=web2x&context=3), it looks like the issue might be with the RGB leds somehow, I think related to the serial connection.

I tried flashing with the sofle/rev1 firmware, and it works! No RGB, but the keyboard works.

I edited my rules.mk to set RGB_MATRIX_ENABLE = no, and modified the keymap.c to only query for the RGB settings if RGB_MATRIX was defined (it was giving a compile error if I disabled RGB_MATRIX without doing this). The keyboard works!

May 18, 2023
RGBLIGHT works, RGB_MATRIX does not.
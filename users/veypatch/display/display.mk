POST_CONFIG_H += $(USER_PATH)/display/config.h

SRC += $(USER_PATH)/display/display.c

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi surface

BACKLIGHT_ENABLE = yes

# Images
SRC += $(USER_PATH)/display/graphics/patchouli.qgf.c

# Fonts
SRC += $(USER_PATH)/display/graphics/fonts/Retron2000-27.qff.c \
       $(USER_PATH)/display/graphics/fonts/Retron2000-underline-27.qff.c \
	   $(USER_PATH)/display/graphics/fonts/thintel15.qff.c \

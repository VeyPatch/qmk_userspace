POST_CONFIG_H += $(USER_PATH)/display/config.h

SRC += $(USER_PATH)/display/display.c

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi surface

BACKLIGHT_ENABLE = yes

# Images
SRC += $(USER_PATH)/display/graphics/patchouli.qgf.c

# Fonts
SRC += $(USER_PATH)/display/graphics/fonts/Retron2000-27.qff.c \
       $(USER_PATH)/display/graphics/fonts/Retron2000-underline-27.qff.c

# Numbers in image format
SRC += $(USER_PATH)/display/graphics/numbers/0.qgf.c \
	   $(USER_PATH)/display/graphics/numbers/1.qgf.c \
	   $(USER_PATH)/display/graphics/numbers/2.qgf.c \
	   $(USER_PATH)/display/graphics/numbers/3.qgf.c \
	   $(USER_PATH)/display/graphics/numbers/4.qgf.c \
	   $(USER_PATH)/display/graphics/numbers/5.qgf.c \
	   $(USER_PATH)/display/graphics/numbers/6.qgf.c \
	   $(USER_PATH)/display/graphics/numbers/7.qgf.c \
	   $(USER_PATH)/display/graphics/numbers/8.qgf.c \
	   $(USER_PATH)/display/graphics/numbers/9.qgf.c \
	   $(USER_PATH)/display/graphics/numbers/undef.qgf.c

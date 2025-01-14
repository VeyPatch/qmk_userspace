SRC += $(USER_PATH)/veypatch.c
INTROSPECTION_KEYMAP_C = $(USER_PATH)/keyrecords/combos.c

# Keyboard features
NKRO_ENABLE = yes
COMBO_ENABLE = yes

# Platform specific features
ifeq ($(PLATFORM_KEY),chibios)
	include $(USER_PATH)/arm/arm.mk
endif

SRC += $(USER_PATH)/veypatch.c
NKRO_ENABLE = yes

ifeq ($(PLATFORM_KEY),chibios)
	include $(USER_PATH)/arm/arm.mk
endif

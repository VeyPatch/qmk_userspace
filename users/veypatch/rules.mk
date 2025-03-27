SRC += $(USER_PATH)/veypatch.c

# Keyboard features
OS_DETECTION_ENABLE = yes

# Platform specific features
ifeq ($(PLATFORM_KEY),chibios)
	include $(USER_PATH)/arm/arm.mk
endif

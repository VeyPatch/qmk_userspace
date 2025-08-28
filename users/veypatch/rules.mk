SRC += $(USER_PATH)/veypatch.c

# Keyboard features
OS_DETECTION_ENABLE = no

# Unicode features
UNICODE_COMMON = yes
UNICODEMAP_ENABLE = yes

# Platform specific features
ifeq ($(PLATFORM_KEY),chibios)
	include $(USER_PATH)/arm/arm.mk
endif

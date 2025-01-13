LTO_ENABLE = no
POST_CONFIG_H += $(USER_PATH)/arm/rgb_matrix_config.h

ifneq ($(filter $(strip $(CONVERT_TO)), imera liatris),)
    include $(USER_PATH)/arm/liatris/liatris.mk
endif

ifeq ($(strip $(KEYBOARD)), veypatch/kyria_mini)
	include $(USER_PATH)/arm/kyria_mini/kyria_mini.mk
endif

ifeq ($(strip $(KEYBOARD)), splitkb/halcyon/kyria/rev4)
  include $(USER_PATH)/arm/halcyon/halcyon.mk
endif

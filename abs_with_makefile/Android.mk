LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

EXAMPLE_DIR := $(LOCAL_PATH)
EXAMPLE_LIB := lib/libexample.a

define all-c-h-files-under
	$(shell find -L $(1) -name "*.[ch]" -and -not -name ".*") 
endef
EXAMPLE_SRC := $(sort $(call all-c-h-files-under, $(EXAMPLE_DIR)))

$(LOCAL_PATH)/$(EXAMPLE_LIB): $(EXAMPLE_SRC)
	@cd $(EXAMPLE_DIR); $(MAKE)


LOCAL_PREBUILT_LIBS := libexample:$(EXAMPLE_LIB)

include $(BUILD_MULTI_PREBUILT)

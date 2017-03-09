LOCAL_PATH := $(call my-dir)

# Build example.jar
# ============================================================
include $(CLEAR_VARS)

EXAMPLE_SUBDIRS := \
	java

LOCAL_SRC_FILES := $(call find-other-java-files, $(EXAMPLE_SUBDIRS))

LOCAL_MODULE_TAGS := eng
LOCAL_MODULE := example
LOCAL_MODULE_CLASS := JAVA_LIBRARIES

LOCAL_NO_EMMA_INSTRUMENT := true
LOCAL_NO_EMMA_COMPILE := true

include $(BUILD_JAVA_LIBRARY)


# Build example.xml
# ============================================================
include $(CLEAR_VARS)
LOCAL_MODULE := example.xml
LOCAL_MODULE_TAGS := eng
LOCAL_MODULE_CLASS := PERMISSION
LOCAL_MODULE_PATH := $(TARGET_OUT_ETC)/permissions
LOCAL_SRC_FILES := example.xml
LOCAL_CERTIFICATE := platform
include $(BUILD_PREBUILT)

include $(call all-makefiles-under, $(LOCAL_PATH))

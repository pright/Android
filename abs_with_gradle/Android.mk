LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := example
LOCAL_MODULE_TAGS := eng
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_PATH := $(ANDROID_PRODUCT_OUT)/system/app
LOCAL_CERTIFICATE := platform
LOCAL_SRC_FILES := example/build/outputs/apk/example-release.apk

PROJECT_PATH := $(LOCAL_PATH)
PROJECT_SRC_DIRS := example

include $(LOCAL_PATH)/gradle.mk

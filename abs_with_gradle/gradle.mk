JAVA_HOME := $(shell pwd)/gradle-build/jdk1.8
ANDROID_HOME := $(shell pwd)/gradle-build/android-sdk
GRADLE_USER_HOME := gradle

TMP_DIR := /tmp/gradle_$(LOCAL_MODULE)

ifneq ($(filter update_deps, $(MAKECMDGOALS)), )

.PHONY: update_deps
update_deps:
	@cd $(PROJECT_PATH); \
	rm -rf $(TMP_DIR); \
	mkdir -p $(TMP_DIR); \
	GRADLE_USER_HOME=$(TMP_DIR) JAVA_HOME=$(JAVA_HOME) ANDROID_HOME=$(ANDROID_HOME) ./gradlew --refresh-dependencies; \
	cp -a $(TMP_DIR)/* $(GRADLE_USER_HOME); \
	rm -rf $(TMP_DIR);

else ifneq ($(filter build_clean, $(MAKECMDGOALS)), )

.PHONY: build_clean
build_clean:
	@cd $(PROJECT_PATH); \
	rm -rf $(TMP_DIR) && \
	ln -sf $$(pwd)/$(GRADLE_USER_HOME) $(TMP_DIR); \
	GRADLE_USER_HOME=$(TMP_DIR) JAVA_HOME=$(JAVA_HOME) ANDROID_HOME=$(ANDROID_HOME) ./gradlew --offline clean; \
	rm -rf $(TMP_DIR);
 
else

ifneq ($(PROJECT_SRC_DIRS), )
define find-related-src-files
	$(call find-subdir-files, $(1) -not -path '*/build/*' -and \( -name "*.java" -or -name "*.xml" -and -not -name ".*" \))
endef
PROJECT_SRC := $(sort $(addprefix $(PROJECT_PATH)/, $(call find-related-src-files, $(PROJECT_SRC_DIRS))))
endif

$(PROJECT_PATH)/$(LOCAL_SRC_FILES): $(PROJECT_SRC)
	@cd $(PROJECT_PATH); \
	rm -rf $(TMP_DIR) && \
	ln -sf $$(pwd)/$(GRADLE_USER_HOME) $(TMP_DIR); \
	GRADLE_USER_HOME=$(TMP_DIR) JAVA_HOME=$(JAVA_HOME) ANDROID_HOME=$(ANDROID_HOME) ./gradlew --offline build; \
	rm -rf $(TMP_DIR);

include $(BUILD_PREBUILT)

endif

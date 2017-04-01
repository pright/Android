JAVA_HOME := $(shell pwd)/gradle-build/jdk1.8
ANDROID_HOME := $(shell pwd)/gradle-build/android-sdk
GRADLE_USER_HOME := gradle

TMP_DIR := /tmp/gradle_$(LOCAL_MODULE)


ifneq ($(filter update_deps, $(MAKECMDGOALS)), )

define INIT_GRADLE
gradle.projectsLoaded {
    rootProject.allprojects {
        buildscript {
            repositories {
                def REPOSITORY_URL = 'http://maven.aliyun.com/nexus/content/groups/public/'
                all { ArtifactRepository repo ->
                    if (repo instanceof MavenArtifactRepository) {
                        def url = repo.url.toString()
                        if (url.startsWith('Central Repository:')
                            || url.startsWith('https://jcenter.bintray.com/')) {
                            project.logger.lifecycle "Repository $${repo.url} replaced by $$REPOSITORY_URL."
                            remove repo
                        }
                    }
                }
                jcenter {
                    url REPOSITORY_URL
                }
            }
        }
        repositories {
            def REPOSITORY_URL = 'http://maven.aliyun.com/nexus/content/groups/public/'
            all { ArtifactRepository repo ->
                if (repo instanceof MavenArtifactRepository) {
                    def url = repo.url.toString()
                    if (url.startsWith('Central Repository:')
                        || url.startsWith('https://jcenter.bintray.com/')) {
                        project.logger.lifecycle "Repository $${repo.url} replaced by $$REPOSITORY_URL."
                        remove repo
                    }
                }
            }
            jcenter {
                url REPOSITORY_URL
            }
        }
    }
}
endef

define GITIGNORE
/daemon/*
/native/*
/caches/*
!/caches/modules-*/
/wrapper/dists/**
!/wrapper/dists/gradle-*/
!/wrapper/dists/gradle-*/*/
!/wrapper/dists/gradle-*/*/*.zip
*.lock
endef


$(GRADLE_USER_HOME)/init.gradle: export INIT_GRADLE:=$(INIT_GRADLE)
$(GRADLE_USER_HOME)/init.gradle:
	@cd $(PROJECT_PATH); \
	echo "$${INIT_GRADLE}" > $@

$(GRADLE_USER_HOME)/.gitignore: export GITIGNORE:=$(GITIGNORE)
$(GRADLE_USER_HOME)/.gitignore:
	@cd $(PROJECT_PATH); \
	echo "$${GITIGNORE}" > $@

.PHONY: prepare
prepare: $(GRADLE_USER_HOME)/init.gradle $(GRADLE_USER_HOME)/.gitignore

.PHONY: update_deps
update_deps: prepare
	@cd $(PROJECT_PATH); \
	rm -rf $(TMP_DIR); \
	mkdir -p $(TMP_DIR); \
	cp -a $(GRADLE_USER_HOME)/* $(TMP_DIR); \
	GRADLE_USER_HOME=$(TMP_DIR) JAVA_HOME=$(JAVA_HOME) ANDROID_HOME=$(ANDROID_HOME) ./gradlew -I $(GRADLE_USER_HOME)/init.gradle --refresh-dependencies; \
	cp -a $(TMP_DIR)/* $(GRADLE_USER_HOME); \
	rm -rf $(TMP_DIR);

else ifneq ($(filter build_clean, $(MAKECMDGOALS)), )

.PHONY: build_clean
build_clean:
	@cd $(PROJECT_PATH); \
	rm -rf $(TMP_DIR) && \
	ln -sf $$(pwd)/$(GRADLE_USER_HOME) $(TMP_DIR); \
	GRADLE_USER_HOME=$(TMP_DIR) JAVA_HOME=$(JAVA_HOME) ANDROID_HOME=$(ANDROID_HOME) ./gradlew -I $(GRADLE_USER_HOME)/init.gradle --offline clean; \
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
	GRADLE_USER_HOME=$(TMP_DIR) JAVA_HOME=$(JAVA_HOME) ANDROID_HOME=$(ANDROID_HOME) ./gradlew -I $(GRADLE_USER_HOME)/init.gradle --offline build; \
	rm -rf $(TMP_DIR);

include $(BUILD_PREBUILT)

endif

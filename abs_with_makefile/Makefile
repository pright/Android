TARGET := libexample.a
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:%.c=%.o)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(AR) rcs $(TARGET) $(OBJECTS)

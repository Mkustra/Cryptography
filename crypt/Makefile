#C Compiler
CC := gcc
FLAGS := -Wall

# Result file name
TARGET_DIR := bin
TARGET := crypt

# Source folder
SRC := src


# Listing all folders in src using shell
SRC_DIRS := ${shell find ${SRC} -type d -print}

# Listing all folders in src without using shell
#SRC_DIRS := ${sort ${dir ${wildcard ${SRC}/*/
#                         ${SRC}/*/*/}}}


# Header files
INC_FILES := $(wildcard *.h) $(foreach D,$(SRC_DIRS),$(wildcard $D/*.h))

# Source files.
SRCS := $(wildcard *.c) $(foreach D,$(SRC_DIRS),$(wildcard $D/*.c))


# Host executable target.
#all : $(TARGET_DIR)/$(TARGET)
all :	$(TARGET) #temporary

#$(TARGET_DIR)/$(TARGET) : build
$(TARGET) : build
	$(CC) $(FLAGS) $(INC_FILES) $(SRCS) -o $(TARGET)
	#$(CC) $(FLAGS) $(INC_FILES) $(SRCS) -o $(TARGET_DIR)/$(TARGET)
build:
	@mkdir -p bin

.PHONY: clean
clean:
	rm -r bin

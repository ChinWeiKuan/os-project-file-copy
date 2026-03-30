# Compiler settings
CC = gcc
CFLAGS = -Wall -g

# Target executable name
TARGET = FileCopy

# Default target
all: $(TARGET)

$(TARGET): FileCopy.c
	$(CC) $(CFLAGS) -o $(TARGET) FileCopy.c

# Clean up build files
clean:
	rm -f $(TARGET)
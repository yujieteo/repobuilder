CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC_DIR = src
TARGET = repobuild
TEST_TARGET = test_repobuild

ARGS = my_git_project 2 Alpha Beta

.PHONY: all run test clean

all: $(TARGET)

# Build main program
$(TARGET): $(SRC_DIR)/main.c $(SRC_DIR)/project_utils.c $(SRC_DIR)/project_utils.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_DIR)/main.c $(SRC_DIR)/project_utils.c

# Build test program
$(TEST_TARGET): $(SRC_DIR)/test.c $(SRC_DIR)/project_utils.c $(SRC_DIR)/project_utils.h
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(SRC_DIR)/test.c $(SRC_DIR)/project_utils.c

# Run program with default args
run: $(TARGET)
	./$(TARGET) $(ARGS)

# Run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean everything
clean:
	rm -f $(TARGET) $(TEST_TARGET)
	rm -rf my_git_project test_project

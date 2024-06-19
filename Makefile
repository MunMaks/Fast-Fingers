# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -g

# Directories setup
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

# All sources & objects
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Executable name
EXEC = $(BIN_DIR)/run

# Default target
fast: $(EXEC)

# Rule to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Rule to link object files into EXEC
$(EXEC): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to clean target
clean: 
	rm -rf $(OBJ_DIR) $(BIN_DIR)/run

.PHONY: clean
.SILENT: clean

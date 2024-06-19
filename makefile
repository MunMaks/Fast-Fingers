CC = gcc
CFLAGS = -std=c17 -ansi -pedantic -Wall -Wfatal-errors -Werror -Wextra -finline-functions -funroll-loops
# OPT = -O2

SRC_DIR = src
INC_DIR = include
OBJ_DIR = build


SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

INC = -I $(INC_DIR)



all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(OPT)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(OPT) $(INC) -c -o $@ $<


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


.PHONY: all clean mrproper uninstall

clean:
	rm -rf $(OBJ_DIR)

mrproper: clean
	rm -f $(EXE)

uninstall: mrproper
	rm -f $(ARCHIVE).zip

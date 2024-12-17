CC = gcc
CFLAGS = -Wall -Wextra -I../src
SRC_DIR = ../src
BIN_DIR = .
OBJ_DIR = ../src
EXEC = main

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/console.c \
       $(SRC_DIR)/ADT/custom/custom.c \
       $(SRC_DIR)/ADT/list/list.c \
       $(SRC_DIR)/ADT/listdin/listdin.c \
       $(SRC_DIR)/ADT/mesinkarakter/mesinkarakter.c \
       $(SRC_DIR)/ADT/mesinkata/mesinkata.c \
       $(SRC_DIR)/ADT/queue/queue.c \
       $(SRC_DIR)/ADT/map/map.c \
       $(SRC_DIR)/game/QuantumWordl3/QuantumWordl3.c \
       $(SRC_DIR)/game/tebakAngka/tebakAngka.c \
       $(SRC_DIR)/game/wordl3/wordl3.c

OBJS = $(SRCS:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(EXEC) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BIN_DIR)/$(EXEC) $(OBJ_DIR)/**/*.o $(OBJ_DIR)/*.o

.PHONY: all clean

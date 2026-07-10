CC = gcc

CFLAGS = -std=c11 -Wall -Wextra -Werror -Iinclude -Isrc/internal

SRC = \
src/main.c \
src/core/pulse.c \
src/ui/ui.c

OBJ = $(SRC:.c=.o)

TARGET = pulse

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -lncurses -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

# variables
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinc
TARGET = sh-ovel
SRC = src/main.c src/builtins.c src/execute.c src/loop.c src/parse.c

OBJ = $(SRC:.c=.o)

# default target
all: $(TARGET)

# link and create exec
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# compile src files into obj files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# clean up
clean:
	rm -f $(OBJ) $(TARGET)

# run the program
run:
	./$(TARGET)

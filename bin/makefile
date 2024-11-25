CC = gcc
CFLAGS = -Wall -Werror -std=c11

# Compile all C files in the src, src/* and src/*/* directories
build:
	$(CC) $(CFLAGS) ../src/main.c -o purrmart

# Run the compiled program
run:
	./purrmart

# Compile and run the program
all:
	build run

# Clean up the compiled program
clean:
	rm main
CC = gcc
CFLAGS = -Wall -Werror -std=c11 -I../src

# Source files
SRCS = ../src/main.c \
       ../src/ADT/dynamiclist/dynamiclist.c \
       ../src/ADT/List/List.c \
       ../src/ADT/mesinkarakter/mesinkarakter.c \
       ../src/ADT/mesinkata/mesinkata.c \
       ../src/ADT/queue/queue.c \
       ../src/ADT/map/map.c \
       ../src/ADT/stack/stack.c \
       ../src/ADT/Listlinier/listlinier.c \
       ../src/COMMAND/LOGIN/LOGIN.c \
       ../src/COMMAND/HELP/HELP.c \
       ../src/COMMAND/LOAD/LOAD.c \
       ../src/COMMAND/LOGOUT/LOGOUT.c \
       ../src/COMMAND/QUANTUM/quantum.c \
       ../src/COMMAND/REGISTER/REGISTER.c \
       ../src/COMMAND/SAVE/SAVE.c \
       ../src/COMMAND/START/START.c \
       ../src/COMMAND/STORE_LIST/store_list.c \
       ../src/COMMAND/STORE_REMOVE/store_remove.c \
       ../src/COMMAND/STORE_REQUEST/store_request.c \
       ../src/COMMAND/STORE_SUPPLY/store_supply.c \
       ../src/COMMAND/CART_ADD/cart_add.c \
       ../src/COMMAND/CART_SHOW/cart_show.c \
       ../src/COMMAND/CART_REMOVE/cart_remove.c \
       ../src/COMMAND/CART_PAY/cart_pay.c \
       ../src/COMMAND/PROFILE/profile.c \
       ../src/COMMAND/WISHLIST_ADD/wishlist_add.c \
       ../src/COMMAND/WISHLIST_REMOVE_1/wishlist_remove_1.c \
       ../src/COMMAND/WISHLIST_REMOVE_2/wishlist_remove_2.c \
       ../src/COMMAND/WISHLIST_CLEAR/wishlist_clear.c \
       ../src/COMMAND/WISHLIST_SHOW/wishlist_show.c \
       ../src/COMMAND/WISHLIST_SWAP/wishlist_swap.c \
       ../src/COMMAND/HISTORY/history.c

OBJS = $(SRCS:.c=.o)
TARGET = purrmart.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /F /Q $(OBJS) $(TARGET)

.PHONY: all clean







# CC = gcc
# CFLAGS = -Wall -Werror -std=c11

# # Compile all C files in the src, src/* and src/*/* directories
# build:
# 	$(CC) $(CFLAGS) ../src/main.c -o purrmart

# # Run the compiled program
# run:
# 	./purrmart

# # Compile and run the program
# all:
# 	build run

# # Clean up the compiled program
# clean:
# 	rm main
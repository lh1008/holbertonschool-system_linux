# compiler: gcc
CC = gcc

# compiler flags
# -Wall
# -Werror
# -Wextra
# -pedantic
CFLAGS = -Wall -Werror -Wextra -pedantic

all: hnm hobjdump

hnm: 0-nm.c
	$(CC) $(CFLAGS) 0-nm.c -o hnm
	cp hnm test_file
	touch 0-nm.c

hobjdump: 1-objdump.c
	$(CC) $(CFLAGS) 1-objdump.c -o hobjdump
	cp hobjdump test_file
	touch 1-objdump.c

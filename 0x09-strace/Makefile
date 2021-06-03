# compiler: gcc
CC = gcc

# compiler flags
# -Wall
# -Werror
# -Wextra
# -pedantic
CFLAGS = -Wall -Werror -Wextra -pedantic
DEPS = syscalls.h strace.h

SRCS0 = strace_0.c
OBJ0 = $(SRCS0:.c=.o)

SRC1 = strace_1.c
OBJ1 = $(SRC1:.c=.o)

all: $(OBJ0)

strace_0: $(OBJ0)
	$(CC) $(CFLAGS) $(DEPS) $(OBJ0) -o strace_0

strace_1: $(OBJ1)
	$(CC) $(CFLAGS) $(DEPS) $(OBJ1) -o strace_1

clean:
	$(RM) *.o
	$(RM) *~
	$(RM) strace_0
	$(RM) strace_1

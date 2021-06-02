# compiler: gcc
CC = gcc

# compiler flags
# -Wall
# -Werror
# -Wextra
# -pedantic
CFLAGS = -Wall -Werror -Wextra -pedantic
DEPS = syscalls.h

SRCS0 = strace_0.c
OBJ0 = $(SRCS0:.c=.o)

all: $(OBJ0)

strace_0: $(OBJ0)
	$(CC) $(CFLAGS) $(DEPS) $(OBJ0) -o strace_0

clean:
	$(RM) *.o
	$(RM) strace_0

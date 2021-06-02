# 0x09. C - Strace

### Learning Objectives

- What is strace, and what is its purpose
- What is ptrace, and what possibilties it offers
- What are the differences between PTRACE_SINGLESTEP and PTRACE_SYSCALL
- How to read from and/or write to the memory of a process being traced

### Tasks

_**0. Step #0 - Syscall number**_
Write a program that executes and traces a given command.

- Usage: `./strace_0 command [args...]`
- Each time a syscall is intercepted, you must print its number, followed by a new line
- You don’t have to handle the `PATH: command` will be a full path to a binary (Ex: `/bin/ls` and not `ls`)
- Your Makefile must implement a rule `strace_0`


_**1. Step #1 - Syscall name**
Write a program that executes and traces a given command.

- Usage: `./strace_1 command [args...]`
- Each time a syscall is intercepted, you must print its name, followed by a new line
- You don’t have to handle the `PATH: command` will be a full path to a binary (Ex: `/bin/ls` and not `ls`)
- Your Makefile must implement a rule `strace_1`

_**2. Step #2 - Return value**_
Write a program that executes and traces a given command.

- Usage: `./strace_2 command [args...]`
- Each time a syscall is intercepted, you must print its name and its return value in hexadecimal, followed by a new line (see example)
- You don’t have to handle the `PATH: command` will be a full path to a binary (Ex: `/bin/ls` and not `ls`)
- Your Makefile must implement a rule `strace_2`
- NOTES: It is impossible to retrieve the last system call return value, simply because it doesn’t return. So, just print a `?` like `strace` does.

_**3. Step #3 - Raw parameters**_
Write a program that executes and traces a given command.

- Usage: ./strace_3 command [args...]
- Each time a syscall is intercepted, you must print its name, its parameters in hexadecimal, and its return value in hexadecimal, followed by a new line (see example)
- There’s a difficulty: The number of parameters is not the same for all syscalls…
- You DON’T have to handle varargs:
  - In case of a variadic system call, just print ...
  - Example with the ioctl syscall: ioctl(0x3, 0x1, ...) = 0 (These are random values…)
- You don’t have to handle the PATH: command will be a full path to a binary (Ex: /bin/ls and not ls)
- Your Makefile must implement a rule strace_3
- NOTE: Refer to the previous x86-64_Assembly project to know where to find the arguments

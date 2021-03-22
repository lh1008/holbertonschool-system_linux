# 0x05. x86 Assembly - libASM

### Learning Objectives

- The differences between `Intel` and `AT&T` syntaxes
- The different x86 GPR
- The different flag registers
- What is a stack frame
- How to setup a stack frame
- How to call a function
- How to make a system call
- How to pass parameters to a function
- How to retrieve parameters

### Tasks

_**0. strlen **_
Write a copycat of the function `strlen`(3), in x86-64 Assembly.

_**1. strcmp**_
Write a copycat of the function `strcmp`(3), in x86-64 Assembly.

_**2. strncmp**_
Write a copycat of the function `strncmp`(3), in x86-64 Assembly

_**3. strchr**_
Write a copycat of the function `strchr`(3), in x86-64 Assembly.

_**4. strstr**_
Write a copycat of the function `strstr`(3), in x86-64 Assembly.

_**5. memcpy**_
Write a copycat of the function `memcpy`(3), in x86-64 Assembly.

_**6. putc**_
Write a function that prints a single character on the standard output, in x86-64 Assembly.

_**7. puts**_
Write a function that prints a string of characters on the standard output, in x86-64 Assembly.

_**8. strcasecmp**_
Write a copycat of the function `strcasecmp`(3), in x86-64 Assembly.

_**9. strncasecmp**_
Write a copycat of the function `strncasecmp`(3), in x86-64 Assembly.

_**10. strspn**_
Write a copycat of the function `strspn`(3), in x86-64 Assembly.

_**11. strcspn**_
Write a copycat of the function `strcspn`(3), in x86-64 Assembly.

_**12. strpbrk**_
Write a copycat of the function `strpbrk`(3), in x86-64 Assembly.

### Compile & Instructions

This project was compiled on `Ubuntu 20.4 LTS`. `ASM` programs and functions were compiled with `NASM version 2.14.02` using flags `-f elf64`. All functions were included in `libasm.h`.

These were compiled using `GCC` (`gcc version 8.4.0`). Make sure you have installed `nasm` in your machine.

Download the project and locate yourself inside the directory where you downloaded it. The files that are not ended with and extension, e.g. `.asm, .c, .h, .o`, are executables and you can execute them in your machine following the aboved examples:

`$ ./0-strlen`

`$ ./5-memcpy`

If you want to compile the `ASM` program follow the following commands. Take notice that you should change the main files with the respective file number, e.g. `0-main`, `0-strlen`. All your files should follow the same compile instructions:

Compile using `gcc` to get the object file `0-main.o`:

`$ gcc -Wall -Wextra -Werror -pedantic -g3 -c -o 0-main.o 0-main.c`

Assemble your `.nasm` files to get object file `0-strlen.o`:

`$ nasm -f elf64 -o 0-strlen.o 0-strlen.asm`

Compile your object files to `link` them together to create the executable:

`$ gcc -o 0-strlen 0-main.o 0-strlen.o`

Execute the created `0-strlen` file:

`$ ./0-strlen`

### Bugs

If you find any issues compiling the files open an [issue](https://github.com/lh1008/holbertonschool-system_linux/issues) in this repository so we can handle it.

### Authors

- @lh1008 with the help of Holberton's peers.

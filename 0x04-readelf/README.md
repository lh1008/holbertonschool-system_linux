# 0x04. C - ELF: readelf

## Learning Objectives

- What is the ELF format
- What kind of files are in the ELF format
- What are the different parts that constitute an ELF file
- What information are present in the file header
- What information are present in the sections header table
- What information are present in the program header table
- How to parse an ELF file using C structures

### Tasks

_**0. ELF file header**_
Write a program that displays the information contained in the `ELF file header` of an `ELF` file.

_**1. ELF sections' headers**_
Write a program that displays the information contained in the `ELF sections' headers` of an `ELF` file.

_**2. ELF program headers**_
Write a program that displays the information contained in the `ELF program headers` of an `ELF` file.

## Instructions

All the files have been compiled on `Ubuntu 20.04` using `gcc 8.4.0` and the flags `-Wall`, `-Werror`, `-Wextra`, and `-pedantic`.

Open up your terminal. Download the following files and locate them in a directory that you will like to try the code out:

- [0-hreadelf.c](https://github.com/lh1008/holbertonschool-system_linux/blob/main/0x04-readelf/0-hreadelf.c)

- [1-hreadelf.c](https://github.com/lh1008/holbertonschool-system_linux/blob/main/0x04-readelf/1-hreadelf.c)

- [2-hreadelf.c](https://github.com/lh1008/holbertonschool-system_linux/blob/main/0x04-readelf/2-hreadelf.c)

- [100-hreadelf.c](https://github.com/lh1008/holbertonschool-system_linux/blob/main/0x04-readelf/100-hreadelf.c)

- [Makefile](https://github.com/lh1008/holbertonschool-system_linux/blob/main/0x04-readelf/Makefile)

Make sure you have installed [`make`](https://www.gnu.org/software/make/).

Run `make` in the directory you located the files:

`$ make`

You will have this output in your terminal:

```
gcc -Wall -Werror -Wextra -pedantic 0-hreadelf.c -o 0-hreadelf
gcc -Wall -Werror -Wextra -pedantic 1-hreadelf.c -o 1-hreadelf
gcc -Wall -Werror -Wextra -pedantic 2-hreadelf.c -o 2-hreadelf
gcc -Wall -Werror -Wextra -pedantic 100-hreadelf.c -o 100-hreadelf
```

To test the executables run the following command:

`$ ./0-hreadelf 0-hreadelf`

Your machine will print the something similar to this `ELF file headers`:

```
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x10c0
  Start of program headers:          64 (bytes into file)
  Start of section headers:          14848 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         13
  Size of section headers:           64 (bytes)
  Number of section headers:         31
  Section header string table index: 30
```

Do the same with the other executables:

`$ ./1-hreadelf 1-readelf`

`$ ./2-hreadelf 2-readelf`

`$ ./100-readelf 100-readelf`

Enjoy! :)

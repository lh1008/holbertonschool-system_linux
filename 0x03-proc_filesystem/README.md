# 0x03. Python - /proc filesystem

### Learning Objectives

- What is the /proc filesystem
- What is the /proc/maps file
- What is the /proc/mem file
- What is the link between those two files
- How does the virtual memory map into the RAM

### Tasks

_**0. Hack the VM**_
Write a script that finds a string in the heap of a running process, and replaces it.

_**1. Blog post #1_
Write a blog post about the `/proc filesystem` and the `/proc/maps` and `/proc/mem` files.

_**2. Blog post #2**_
Write a blog post about the virtual memory.

### Instructions

This program has been compiled using `gcc version 8.4.0` and `Python 3.8.5`.

Download [`loop.c`](https://raw.githubusercontent.com/lh1008/holbertonschool-system_linux/main/0x03-proc_filesystem/holberton.c) and [`read_write_heap.py`](https://raw.githubusercontent.com/lh1008/holbertonschool-system_linux/main/0x03-proc_filesystem/read_write_heap.py) files to your system.

Compile `loop.c` file:

`$ gcc loop.c -o loop`

Add executable permissions to `read_write_heap.py`:

`$ chmod u+x read_write_heap.py`

Open another terminal window. In one window execute the compiled `loop` file.

`$ ./loop`


You will see a process running in your machine.

```
[0] Holberton (0x5567335342a0)
[1] Holberton (0x5567335342a0)
[2] Holberton (0x5567335342a0)
[3] Holberton (0x5567335342a0)
[4] Holberton (0x5567335342a0)
...
```

Check the `PID` of the running process in a different terminal window:

`$ ps aux | grep ./loop | grep -v grep`

```
your_pc   6778  0.0  0.0  8789  564 pts/14  S+  14:25  0:00  ./loop
```
`6778` is your running process.

Execute in the new terminal window as root the `read_write_heap.py` file with the following line:

`$ sudo ./read_write_heap.py 6778 Holberton "C is fun"`

Go back to the window where you were executing the process (`loop`). And see how the virtual memory has changed to `"C is fun"`.

```
[292] Holberton (0x55ac6a7d92a0)
[293] Holberton (0x55ac6a7d92a0)
[294] Holberton (0x55ac6a7d92a0)
[295] Holberton (0x55ac6a7d92a0)
[296] Holberton (0x55ac6a7d92a0)
[297] C is fun (0x55ac6a7d92a0)
[298] C is fun (0x55ac6a7d92a0)
[299] C is fun (0x55ac6a7d92a0)
[300] C is fun (0x55ac6a7d92a0)
[301] C is fun (0x55ac6a7d92a0)
...
```

Enjoy! :)

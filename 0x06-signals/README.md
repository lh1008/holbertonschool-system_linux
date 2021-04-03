# 0x06. C - Signals

### Learning Objectives

- What is a signal
- Why do they exist
- When are they delivered and by whom
- What are the default actions of signals
- How to set up a handler for a signal
- How to send signals
- What signals can’t be caught

### Tasks

_**0. Handle signal**_
Write a function that set a handler for the signal `SIGINT`.

_**1. Current handler - signal**_
Write a function that retrieves the current handler of the signal SIGINT.

_**2. Gotta catch them all**_
Write a function that set a handler for the signal `SIGINT`.

_**3. Current handler - sigaction**_
Write a function that retrieves the current handler of the signal SIGINT.

_**4. Who said that?!**_
Write a function that defines a handler for the signal `SIGQUIT` (`Control-\` in a shell)

_**5. Description**_
Write a program that prints a description of a given signal

_**6. Catch a single time**_
Write a program that sets a handler for the signal `SIGINT`, and exits right after the signal is received and handled.

_**7. Sending a signal**_
Write a program that sends the signal `SIGINT` to a process, given its PID.

_**8. Sending a signal in a shell**_
Write a `sh` script that sends the signal `SIGQUIT` to a process, given its PID.

_**9. Catch with sh**_
Write a `sh` script that set a handler for the signals `SIGABRT`, `SIGIO` and `SIGTERM`

_**10. Does it exist?**_
Write a function that tests if a process exists, given its PID.

_**11. Blog post**_
Write a blog post about signals

Your blog post should cover the following:

- What is a signal
- Why do they exist
- When are they delivered and by whom
- What are the default actions of signals
- What happens to a process when it receives a signal without handling it
- What happens to a process when it receives a signal and handles it

#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int handle_signal(void);
void handler(int signum);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
int main(int argc, char *argv[]);

#endif /* SIGNALS_H */

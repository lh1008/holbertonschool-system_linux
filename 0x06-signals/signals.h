#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int handle_signal(void);
void handler(int signum);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);

#endif /* SIGNALS_H */

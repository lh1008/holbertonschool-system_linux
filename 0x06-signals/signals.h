#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#ifndef sigset_t
typedef void (*handler)(int);
#endif /* sigset_t */

int handle_signal(void);
void handler(int signum);
void (*current_handler_signal(void))(int);

#endif /* SIGNALS_H */

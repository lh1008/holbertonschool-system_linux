#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int handle_signal(void);
void handler(int signum);

#endif /* SIGNALS_H */

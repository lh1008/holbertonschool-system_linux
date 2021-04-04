#include "signals.h"

/**
 * handler - handler entry
 * Desc: function to print signal
 * @signum: int signal
 * Return: print 'Gotcha!'
 */
void handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

/**
 * handle_signal - entry to handle_signal
 * Desc: handler_signal that set a handler for a signal SIGINT
 * Return: 0 in success or -1 on error
 */
int handle_signal(void)
{
	if (signal(SIGINT, handler) != SIG_ERR)
		return (0);
	else
		return (-1);

}

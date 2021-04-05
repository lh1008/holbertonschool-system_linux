#include "signals.h"

/**
 * handler - handler entry
 * Desc: function to print signal
 * @signum: int signal
 * Return: print 'Gotcha!'
 */
void _handler()
{
	printf("SIGQUIT sent by %d\n", getpid());
	fflush(stdout);
}

/**
 * handle_signal - entry to handle_signal
 * Desc: handler_signal that set a handler for a signal SIGINT
 * Return: 0 in success or -1 on error
 */
int trace_signal_sender(void)
{
	if (signal(SIGQUIT, _handler) != SIG_ERR)
		return (0);
	else
		return (-1);

}

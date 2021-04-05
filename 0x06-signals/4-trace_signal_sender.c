#include "signals.h"

/**
 * _handler - _handler entry
 * Desc: function to print process ID
 * @signum: int signal
 * Return: print 'SIGQUIT sent by...'
 */
void _handler(int signum)
{
	signum = getpid();

	printf("SIGQUIT sent by %d\n", signum);
	fflush(stdout);
}

/**
 * trace_signal_sender - entry to trace_signal_sender
 * Desc: trace_signal_sender that set a handler for a signal SIGQUIT
 * Return: 0 in success or -1 on error
 */
int trace_signal_sender(void)
{
	if (signal(SIGQUIT, _handler) != SIG_ERR)
		return (0);
	else
		return (-1);

}

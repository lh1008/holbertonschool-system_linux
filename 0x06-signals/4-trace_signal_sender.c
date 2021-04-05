#include "signals.h"

/**
 * get_pid_handler - get_pid_handler entry
 * Desc: function to print process ID
 * @signum: int signal
 * @info: pointer siginfo_t size
 * @context: void type
 * Return: print 'SIGQUIT sent by...'
 */
void get_pid_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)context;

	printf("SIGQUIT sent by %d\n", info->si_pid);
	fflush(stdout);
}

/**
 * trace_signal_sender - entry to trace_signal_sender
 * Desc: trace_signal_sender that set a handler for a signal SIGQUIT
 * Return: 0 in success or -1 on error
 */
int trace_signal_sender(void)
{
	struct sigaction new_action;

	new_action.sa_flags = SA_SIGINFO;
	new_action.sa_sigaction = get_pid_handler;

	if (sigaction(SIGQUIT, &new_action, NULL) < 0)
		return (-1);
	else
		return (0);

}

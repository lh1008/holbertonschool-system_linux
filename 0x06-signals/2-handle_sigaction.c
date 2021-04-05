#include "signals.h"


/**
 * handle_sigaction - entry to handle_action
 * Desc: handler_sigaction that set a handler for a signal SIGINT
 * Return: 0 in success or -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction new_action, old_action;

	new_action.sa_handler = handler;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;

	if (sigaction(SIGINT, &new_action, &old_action) < 0)
		return (-1);
	else if (new_action.sa_handler == SIG_DFL)
		return (0);
	else if (new_action.sa_handler == SIG_IGN)
		return (0);

	return (1);

}

/**
 * handler - handler entry
 * Desc: function to print signal
 * @signum: int signal
 * Return: print 'Gotcha!'
 */
void handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}

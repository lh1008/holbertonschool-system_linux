#include "signals.h"

/**
 * current_handler_sigaction - entry to current_handler_sigaction
 * Desc: handler_sigaction that set a handler for a signal SIGINT
 * Return: 0 in success or -1 on error
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction new_action;

	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;

	if (sigaction(SIGINT, &new_action, NULL) == -1)
		return (NULL);
	else if (new_action.sa_handler == SIG_DFL)
		return (new_action.sa_handler);
	else if (new_action.sa_handler == SIG_IGN)
		return (new_action.sa_handler);

}

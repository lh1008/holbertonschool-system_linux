#include "signals.h"

/**
 * handle_signal - entry to handle_signal
 * Desc: handler_signal that set a handler for a signal SIGINT
 * Return: 0 in success or -1 on error
 */
void (*current_handler_signal(void))(int)
{
	sigset_t handler;

	handler = signal(SIGINT, SIG_DFL);

	if (signal(SIGINT, handler) != SIG_ERR)
		return (NULL);
	else
		return (handler);

}

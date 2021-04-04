#include "signals.h"

/**
 * current_handler_signal - entry to handle_signal
 * Desc: handler_signal that set a handler for a signal SIGINT
 * @void: void int
 * Return: 0 in success or -1 on error
 */
void (*current_handler_signal(void))(int)
{
	void (*handler)(int);

	handler = signal(SIGINT, SIG_DFL);

	if (signal(SIGINT, handler) == SIG_ERR)
		return (NULL);
	else
		return (handler);

}

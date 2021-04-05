#include "signals.h"

/**
 * signal_handler - entry to signal_handler
 * Desc: function that kills self
 * @signum: the signal number
 * @info: info struct about signal
 * @context: pointer to ucontext_t
 */
void signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;

	printf("Caught %d\n", signum);
	fflush(stdout);

}

/**
 * get_signal - entry to get_signal
 * Desc: function that sets the signal here
 * Return: 0 on success else -1 on error
 */
int get_signal(void)
{
	struct sigaction new_action;

	new_action.sa_flags = SA_SIGINFO;
	new_action.sa_sigaction = signal_handler;

	return (sigaction(SIGINT, &new_action, NULL));
}

/**
 * main - entry to main
 * Desc: function that recieves the signal
 * Return: Always success
 */
int main(void)
{
	get_signal();
	pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}

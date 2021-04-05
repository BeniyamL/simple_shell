#include "holberton.h"

/**
 * handleSignal - will handle signal sent to the program
 * @sigInt: signal value
 *
 * Return: nothing
 */
void _signal()
{
	struct sigaction sa;
	sa.sa_handler = &signalHandler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}

/**
 * signalHandler - will handle program signals
 * @sigInt: signal value
 *
 * Return: nothing
 */
void signalHandler(int __attribute__((__unused__)) sigInt)
{
	return;
}

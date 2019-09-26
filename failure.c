#include "monty.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * failure - print an error message and exit
 * @fmt: format string
 * @...: format string parameters
 *
 * Description: Print a message on stderr and exit with status EXIT_FAILURE.
 */
void failure(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);

	vfprintf(stderr, fmt, args);

	va_end(args);

	exit(EXIT_FAILURE);
}

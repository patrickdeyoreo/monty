#include "getln.h"

/**
 * fgetln - get a line from a file
 * @line_p: pointer to the line buffer
 * @size_p: pointer to the line buffer size
 * @stream: pointer to the input stream
 *
 * Return: If memory allocation fails, return -1.
 * Otherwise, return the line length (linefeed included).
 */
ssize_t fgetln(char **line_p, size_t *size_p, FILE *stream)
{
	return (getln(line_p, size_p, fileno(stream)));
}

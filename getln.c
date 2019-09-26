#include "getln.h"
#include "alloc.h"

#include <string.h>
#include <unistd.h>

/**
 * getln - get a single line of input
 *
 * @line_p: pointer to the line_p buffer
 * @size_p: pointer to the size_p of *line_p
 * @fd: file descriptor to read from
 *
 * Return: If memory allocation fails, return -1.
 * Otherwise, return the line length (linefeed included).
 */
ssize_t getln(char **line_p, size_t *size_p, int fd)
{
	static buf_t buf = {{0}, buf.buffer, buf.buffer};
	ssize_t n_read = 0;
	ssize_t len = 0;

	if (!(line_p && size_p) || fd < 0)
		return (-1);

	if (_getln_next(&buf, &len, line_p, size_p))
		return (len);

	while ((n_read = read(fd, buf.w_pos, buf.buffer + BUFSIZ - buf.w_pos)))
	{
		if (n_read < 0)
		{
			free(*line_p);
			*line_p = NULL;
			*size_p = 0;
			return (-1);
		}
		buf.w_pos += n_read;

		if (_getln_next(&buf, &len, line_p, size_p))
			return (len);

		if (_getln_full(&buf, &len, line_p, size_p) < 0)
			return (-1);
	}
	if (!*line_p)
	{
		*line_p = malloc(sizeof(char));
		if (!*line_p)
		{
			*size_p = 0;
			return (-1);
		}
		*size_p = 1;
		**line_p = '\0';
	}
	return (len);
}

/**
 * _getln_next - get a line_p from the buffer
 * @buf: pointer to the buffer structure to read from
 * @len: pointer to the current line_p length
 * @line_p: pointer to the line_p buffer
 * @size_p: pointer to the size_p of the line_p buffer
 *
 * Return: If memory allocation fails, return -1.
 * If a linefeed is not found in the buffer, return 0.
 * Otherwise, return the line length (linefeed included).
 */
ssize_t _getln_next(buf_t *buf, ssize_t *len, char **line_p, size_t *size_p)
{
	char *new = NULL;
	char *linefeed = memchr(buf->r_pos, '\n', buf->w_pos - buf->r_pos);
	size_t eol = linefeed - buf->r_pos;
	size_t new_size = *len + eol + 2;

	if (!linefeed)
		return (0);

	if (*size_p < new_size)
	{
		if (*line_p)
			new = _realloc(*line_p, *size_p, sizeof(char) * new_size);
		else
			new = malloc(sizeof(char) * new_size);

		if (!new)
		{
			free(*line_p);
			*line_p = NULL;
			*size_p = 0;
			*len = (-1);
			return (-1);
		}
		*line_p = new;
		*size_p = new_size;
	}
	memcpy(*line_p + *len, buf->r_pos, eol + 1);

	*len += eol + 1;

	(*line_p)[*len] = '\0';

	if (buf->r_pos + eol + 1 < buf->w_pos)
		buf->r_pos += eol + 1;
	else
		buf->r_pos = buf->w_pos = buf->buffer;

	return (*len);
}

/**
 * _getln_full - copy the whole buffer
 * @buf: pointer to the buffer structure to read from
 * @len: pointer to the current line_p length
 * @line_p: pointer to the line_p buffer
 * @size_p: pointer to the size_p of the line_p buffer
 *
 * Return: If memory allocation fails, return -1.
 * Otherwise, return the line length (linefeed included).
 */
ssize_t _getln_full(buf_t *buf, ssize_t *len, char **line_p, size_t *size_p)
{
	char *new;
	size_t n_remaining = buf->w_pos - buf->r_pos;
	size_t new_size = *len + n_remaining + 1;

	if (*size_p < new_size)
	{
		if (*line_p)
			new = _realloc(*line_p, *size_p, sizeof(char) * new_size);
		else
			new = malloc(sizeof(char) * new_size);

		if (!new)
		{
			free(*line_p);
			*line_p = NULL;
			*size_p = 0;
			*len = (-1);
			return (-1);
		}
		*line_p = new;
		*size_p = new_size;
	}
	memcpy(*line_p + *len, buf->r_pos, n_remaining);

	*len += n_remaining;

	(*line_p)[*len] = '\0';

	buf->r_pos = buf->w_pos = buf->buffer;

	return (*len);
}

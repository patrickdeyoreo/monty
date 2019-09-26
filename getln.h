#ifndef GETLN_H
#define GETLN_H

#include <stdio.h>
#include <stdlib.h>

#ifndef BUFSIZ
#define BUFSIZ 8192
#endif

/**
 * struct buf_s - a buffer structure
 * @buffer: the buffer
 * @r_pos: the read position
 * @w_pos: the write position
 */
typedef struct buf_s
{
	char buffer[BUFSIZ];
	char *r_pos;
	char *w_pos;
} buf_t;

ssize_t getln(char **line_p, size_t *size_p, int fd);

ssize_t fgetln(char **line_p, size_t *size_p, FILE *stream);

ssize_t _getln_next(buf_t *buf, ssize_t *len, char **line_p, size_t *size_p);
ssize_t _getln_full(buf_t *buf, ssize_t *len, char **line_p, size_t *size_p);

void *_realloc(void *ptr, size_t old_size, size_t new_size);

#endif /* GETLN_H */

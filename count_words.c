#include "words.h"
#include <ctype.h>

/**
 * count_words - count the words in a string
 * @str: the string to evaluate
 * Return: If str is NULL, return -1.
 * Otherwise, return the number of words in str.
 */
size_t count_words(const char *str)
{
	size_t count = 0;

	while (*str)
	{
		while (isspace(*str))
			++str;
		if (!*str)
			break;
		do {
			++str;
		} while (*str && !isspace(*str));

		++count;
	}
	return (count);
}


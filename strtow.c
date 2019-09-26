#include "words.h"
#include <ctype.h>
#include <string.h>

/**
 * strtow - split a string into words
 * @str: the string to strtow
 * Return: If memory allocation fails, or if str is NULL or contains no words,
 * return NULL. Otherwise, return a NULL-terminated array of the words in str.
 */
char **strtow(const char *str)
{
	char **words = NULL;
	const char *word = NULL;
	size_t count = 0;

	if (!str)
		return (NULL);

	count = count_words(str);
	if (!count)
		return (NULL);

	words = malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);

	count = 0;
	while (*str)
	{
		while (isspace(*str))
			++str;
		if (!*str)
			break;
		word = str;
		do {
			++str;
		} while (*str && !isspace(*str));

		words[count] = malloc(sizeof(char) * (str - word + 1));
		if (!words[count])
		{
			free_words(&words);
			return (NULL);
		}
		memcpy(words[count], word, str - word);
		words[count][str - word] = '\0';
		++count;
	}
	words[count] = NULL;

	return (words);
}

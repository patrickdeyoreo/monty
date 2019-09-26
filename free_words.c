#include "words.h"

/**
 * free_words - free and nullify an array of words
 * @words: a pointer to an array of words
 */
void free_words(char ***words)
{
	char **tmp = NULL;

	if (words && *words)
	{
		tmp = *words;
		while (*tmp)
			free(*tmp++);
		free(*words);

		*words = NULL;
	}
}


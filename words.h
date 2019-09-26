#ifndef WORDS_H
#define WORDS_H

#include <stdlib.h>

char **strtow(const char *str);
size_t count_words(const char *str);
void free_words(char ***words);

#endif /* WORDS_H */

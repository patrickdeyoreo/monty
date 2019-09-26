#include "getln.h"
#include <string.h>

/**
 * _realloc - reallocate a memory block using malloc and free
 * @ptr: memory previously allocated by malloc, calloc or realloc
 * @old_size: the current size (in bytes) of the memory block
 * @new_size: the desired size (in bytes) of the memory block
 *
 * Description: Contents of the existing memory (if any) will be copied to the
 * newly allocated memory from ptr up to the minimum of old_size and new_size.
 * Additional memory will not be initialized.
 *
 * Return: If new_size is equal to old_size, do nothing and return ptr.
 * If new_size is equal to zero and ptr is non-NULL, free ptr and return NULL.
 * If new_size is non-zero, try to allocate a block of memory of size new_size.
 * If memory allocation fails, return NULL. Otherwise, return a pointer to the
 * newly allocated memory.
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new = NULL;

	if (old_size == new_size)
		return (ptr);

	if (!ptr)
		return (malloc(new_size));

	if (new_size)
	{
		new = malloc(new_size);
		if (!new)
			return (NULL);

		if (old_size < new_size)
			memcpy(new, ptr, old_size);
		else
			memcpy(new, ptr, new_size);
	}
	free(ptr);

	return (new);
}

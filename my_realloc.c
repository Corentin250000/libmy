/*
** EPITECH PROJECT, 2025
** my_realloc.c
** File description:
** ...
*/

#include "my.h"

static void *replace_value(void *ptr, void *new_ptr, size_t previous_size)
{
    void *temp_ptr = ptr;
    void *temp_new_ptr = new_ptr;

    for (size_t i = 0; i < previous_size; ++i) {
        *((char *) new_ptr) = *((char *) ptr);
        ptr++;
        new_ptr++;
    }
    ptr = temp_ptr;
    free(ptr);
    new_ptr = temp_new_ptr;
    return new_ptr;
}

/*
Reallocate the pointer to new size, copy previous data into the new pointer and
free the old pointer.

If ptr is NULL -> do a malloc of given size and return the new pointer.

If size is inferior to 1 and ptr not NULL -> return old pointer and error
variable is put at 1.

In case of allocation error -> return old pointer and error variable is put
at 1.

If the function return NULL -> you must free yourself the pointer.

The previous size parameter is the size of actual pointer (ptr).
*/
void *my_realloc(void *ptr, size_t new_size, size_t previous_size, int *error)
{
    void *new_ptr;

    if (!ptr) {
        new_ptr = malloc(new_size);
        return new_ptr;
    } else if (new_size < 1) {
        *error = 1;
        return ptr;
    }
    new_ptr = malloc(new_size);
    if (!new_ptr) {
        *error = 1;
        return ptr;
    }
    return replace_value(ptr, new_ptr, previous_size);
}

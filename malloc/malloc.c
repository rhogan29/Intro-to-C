#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/
char *string_dup(char *src)
{
    // char pointer that we'll return
    char *str;
    // another pointer that we'll use to write to the allocated memory
    char *p;
    int len = string_length(src);
    // allocate memory for string
    str = malloc(len + 1);
    // set p pointer to point to the same spot as the `str` pointer
    p = str;

    while (*src) {
        // advance the p pointer, copying each char from src
        *p++ = *src++;
    }
    // don't forget to add the null terminator
    *p = '\0';
    // return str because str points to the beginning of the string
    // p points to the null terminator at the end
    return str;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    You may want to cast the input pointers to char pointers first before
    performing the copying. 
*/
void *mem_copy(void *dest, const void *src, int n)
{
    char *csrc = (char *) src;
    char *cdest = (char *) dest;

    for (int i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }

    return dest;
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));
    
    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    printf("\n");

    return 0;
}
#endif

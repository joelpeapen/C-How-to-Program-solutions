// Exercise 15.6 
// dynamic array allocation
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 0;
    printf("%s", "Enter array size: ");
    scanf("%i", &size);

    int* array = calloc(size, sizeof(int));

    printf("%s", "Enter element: ");
    for (size_t i = 0; i < size; i++) {
        scanf("%i", &array[i]);
    }

    puts("\nArray: ");
    for (size_t i = 0; i < size; i++) {
        printf("%i  ", array[i]);
    }

    // reallocate array to half its size
    size /= 2;
    array = realloc(array, size * sizeof(int));

    puts("\nArray after realloc: ");
    for (size_t i = 0; i < size; i++) {
        printf("%i  ", array[i]);
    }

    free(array);

    return 0;
}

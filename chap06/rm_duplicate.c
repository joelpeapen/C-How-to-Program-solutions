#include <stdbool.h>
#include <stdio.h>
#define SIZE 20

bool inArray(int a[], int element, size_t size);

int main(int argc, char const* argv[])
{
    // accept 20 ints in 10-100
    int array[20] = { 0 };
    for (size_t i = 0; i < SIZE; i++) {
        printf("%s", "Enter number between 10 & 100: ");
        scanf("%i", &array[i]);

        if (!inArray(array, array[i], SIZE)) // if not duplicate print
            printf("%i\n", array[i]);
    }

    for (size_t i = 0; i < SIZE; i++) {
        printf("array[%zu]: %i\n", i, array[i]);
    }

    return 0;
}

bool inArray(int a[], int element, size_t size)
{
    int total = 0;
    for (size_t i = 0; i < SIZE; i++) {
        if (a[i] == element)
            total++;

        if (total > 1) // if more than one of same value
            return true;
    }
    return false;
}
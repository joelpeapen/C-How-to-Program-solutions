#include <stdbool.h>
#include <stdio.h>

#define SIZE 20

bool inArray(int a[], int element, size_t size);

int main() {
    // accept 20 ints in 10-100
    int array[20] = { 0 };

    printf("Enter %i numbers between 10 & 100: ", SIZE);
    for (size_t i = 0; i < SIZE; i++) {
        printf("%s", "? ");
        scanf("%i", &array[i]);

        if (!inArray(array, array[i], SIZE)) // if not duplicate print
            printf("%i\n", array[i]);
    }

    puts("\nArray: ");
    for (size_t i = 0; i < SIZE; i++) {
        printf("%i ", array[i]);
    }

    return 0;
}

bool inArray(int a[], int element, size_t size) {
    int total = 0;
    for (size_t i = 0; i < SIZE; i++) {
        if (a[i] == element)
            total++; // count duplicates

        if (total > 1) // if duplicate
            return true;
    }
    return false;
}

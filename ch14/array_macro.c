#include <stdio.h>

#define PRINTARRAY(a, n)          \
    for (int i = 0; i < n; i++) { \
        printf("%i ", a[i]);      \
    }

#define SUMARRAY(a, n)            \
    int sum = 0;                  \
    for (int i = 0; i < n; i++) { \
        sum += a[i];              \
    }                             \
    printf("\nSum: %i", sum);

int main() {
    int array[5] = { 1, 2, 3, 4, 5 };
    PRINTARRAY(array, 5);
    SUMARRAY(array, 5);

    return 0;
}

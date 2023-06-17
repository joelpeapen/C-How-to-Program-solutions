// 15.4
// sort array ascending or descending based on cli argument
#include <stdio.h>

void bubbleSort(int work[], size_t size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);

int main(int argc, char const* argv[]) {
    int array[10] = { 2, 3, 4, 5, 8, 9, 7, 6, 1, 10 };

    puts("Unsorted: ");
    for (size_t i = 0; i < 10; i++) {
        printf("%i  ", array[i]);
    }

    //  sort array based on argv[0];
    bubbleSort(array, 10, ((*argv[1] == 'a') ? ascending : descending));

    printf("\nSorted %s\n: ", ((*argv[1] == 'a') ? "ascending" : "descending"));
    for (size_t i = 0; i < 10; i++) {
        printf("%i  ", array[i]);
    }

    for (int i = 0; i < argc; i++) {
        printf("command[%i] is %s\n", i, argv[i]);
    }

    return 0;
}

void bubbleSort(int work[], size_t size, int (*compare)(int a, int b)) {
    void swap(int* element1Ptr, int* element2ptr);
    for (int pass = 1; pass < size; ++pass) {
        for (size_t count = 0; count < size - 1; ++count) {
            if ((*compare)(work[count], work[count + 1])) {
                swap(&work[count], &work[count + 1]);
            }
        }
    }
}

void swap(int* element1Ptr, int* element2Ptr) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

int ascending(int a, int b) {
    return b < a; // should swap if b is less than a
}

int descending(int a, int b) {
    return b > a; // should swap if b is greater than a
}

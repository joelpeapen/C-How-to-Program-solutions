#include <stdio.h>
#define MINIMUM2(x, y) (x < y) ? x : y
#define MINIMUM3(x, y, z) MINIMUM2(MINIMUM2(x, y), z)

int main() {
    int x = 0, y = 0, z = 0;
    printf("%s", "Enter x, y: ");
    scanf("%i%i", &x, &y);

    printf("\nSmallest: %i", MINIMUM2(x, y));

    printf("\n%s", "Enter x, y, z: ");
    scanf("%i%i%i", &x, &y, &z);

    printf("\nSmallest: %i", MINIMUM3(x, y, z));

    return 0;
}

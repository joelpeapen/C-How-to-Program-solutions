#include <stdio.h>
#define SUM(x, y) x + y

int main() {
    int x, y;
    printf("%s", "enter x, y: ");
    scanf("%i%i", &x, &y);

    printf("sum: %i", SUM(x, y));

    return 0;
}

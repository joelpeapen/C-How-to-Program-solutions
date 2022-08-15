#include <stdio.h>

int main(void)
{
    int x = 0;
    puts("enter 5-digit number: ");
    scanf("%d", &x);

    printf("%d\t", ((x % 100000) - (x % 10000)) / 10000); // get first digit
    printf("%d\t", ((x % 10000) - (x % 1000)) / 1000);    // get 2nd
    printf("%d\t", ((x % 1000) - (x % 100)) / 100);       // get 3rd
    printf("%d\t", ((x % 100) - (x % 10)) / 10);          // get 4th
    printf("%d", x % 10);                                 // get 5th

    return 0;
}

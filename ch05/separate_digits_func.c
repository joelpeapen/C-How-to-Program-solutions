#include <math.h>
#include <stdio.h>

void separate(int num);

int main(void) {
    int x = 0;
    puts("enter 5-digit number: ");
    scanf("%d", &x);

    separate(x);

    // printf("%i ", ((x % 100000) - (x % 10000)) / 10000); // get first digit
    // printf("%i ", ((x % 10000) - (x % 1000)) / 1000); // get 2nd
    // printf("%i ", ((x % 1000) - (x % 100)) / 100); // get 3rd
    // printf("%i ", ((x % 100) - (x % 10)) / 10); // get 4th
    // printf("%i", x % 10); // get 5th

    return 0;
}

void separate(int num) {
    // find number of digits
    double digits = log10(num) + 1;
    // for num of digits find individual digits
    for (int i = 0; i < digits; i++) {
        printf("%i\t", ((num % (pow(10, digits))) - (num % (pow(10, digits - i)))) / pow(10, digits - (i + 1)));
    }
}

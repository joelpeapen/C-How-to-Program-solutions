// 15.2
// Write a program that calculates the product of a series of integers that are passed to function product using a variable- length argument list
#include <stdarg.h>
#include <stdio.h>

int calculate_product(int, ...);

int main() {
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    printf("The product of [1,2] is %i", calculate_product(2, a, b));
    printf("\nThe product of [1,2,3,4] is %i", calculate_product(4, a, b, c, d));
    printf("\nThe product of [1,2,3,4,5] is %i", calculate_product(5, a, b, c, d, e));

    return 0;
}

int calculate_product(int i, ...) {

    int product = 1; // initialize product
    va_list ap; // stores information needed by va_start and va_end
    va_start(ap, i); // initializes the va_list object

    // process variable-length argument list
    for (int j = 1; j <= i; ++j) {
        product *= va_arg(ap, int);
    }

    va_end(ap); // clean up variable-length argument list
    return product; // calculate average
}

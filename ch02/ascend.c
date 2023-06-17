#include <stdio.h>

int main(void) {
    int a = 0, b = 0, c = 0;

    // ask for three ints
    printf("%s", "enter number one: ");
    scanf("%d", &a);

    printf("%s", "enter number two: ");
    scanf("%d", &b);

    printf("%s", "enter number three: ");
    scanf("%d", &c);

    // vars to store in order
    int one = 0, two = 0, three = 0;

    if (a > b && a > c) {
        one = a;
        if (b > c) {
            two = b;
            three = c;
        } else {
            two = c;
            three = b;
        }
    }
    else if (b > a && b > c) {
        one = b;
        if (a > c) {
            two = a;
            three = c;
        } else {
            two = c;
            three = a;
        }
    } else if (c > a && c > b) {
        one = c;
        if (a > b) {
            two = a;
            three = b;
        } else {
            two = b;
            three = a;
        }
    }

    // print each number seperated by tab
    printf("%d\t%d\t%d\t", three, two, one);

    return 0;
}

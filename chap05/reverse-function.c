#include <stdio.h>

int reverse(int);

int main(int argc, char const *argv[])
{
    int n = 0;
    printf("%s", "Enter number: ");
    scanf("%i", &n);

    printf("Reverse: %i", reverse(n));

    return 0;
}

int reverse(int a)
{
    int reverse = 0;
    while (a != 0)
    {
        reverse *= 10;
        reverse += a % 10;
        a /= 10;
    }
    return reverse;
}

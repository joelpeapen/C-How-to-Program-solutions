#include <math.h>
#include <stdio.h>

void separate(int num);

int main(void)
{
    int x = 0;
    puts("enter 5-digit number: ");
    scanf("%d", &x);

    separate(x);

    // ((x % 100000) - (x % 10000)) / 10000) get first digit
    // ((x % 10000) - (x % 1000)) / 1000)    get 2nd
    // ((x % 1000) - (x % 100)) / 100)       get 3rd
    // ((x % 100) - (x % 10)) / 10)          get 4th
    //  x % 10)                              get 5th

    return 0;
}

void separate(int num)
{
    // find digits
    int digits = 0, numCopy = 0;
    while (numCopy != 0)
    {
        digits++;
        numCopy /= 10;
    }
    // for num of digits find individual digits
    for (int i = 0; i < digits; i++)
    {
        printf("%i\t", ((num % (pow(10, digits - i))) - (num % (pow(10, digits - i)))) / pow(10, digits - (i + 1)));
    }
}
#include <stdio.h>

int main(void)
{
    int age;
    puts("enter your age: ");
    scanf("%d", &age);

    int maxRate = 220 - age;
    int target = 50 - 0.85 * age;

    printf("Your maximum heart rate is: %d\n", maxRate);
    printf("Your target heart rate is %d", target);

    return 0;
}

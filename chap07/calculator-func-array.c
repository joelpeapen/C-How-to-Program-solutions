// calculate circumference, area, sphere volume w/ funtion pointers
#include <stdio.h>
#define PI 3.1416

void add(double num, double num2);
void sub(double num, double num2);
void times(double num, double num2);
void divide(double num, double num2);

int main(void)
{
    void (*calculate[4])(double num, double num2) = { add, sub, times, divide };
    int choice = 0;
    double num = 0, num2 = 0;

    printf("%s", "Enter a choice: \n");
    puts(" 0  for Addition");
    puts(" 1  for Subtraction");
    puts(" 2  for Multiplication");
    puts(" 3  for Division");
    scanf("%i", &choice);

    printf("%s", "Enter first number: ");
    scanf("%lf", &num);
    printf("%s", "Enter second number: ");
    scanf("%lf", &num2);

    while (choice != 5 || choice >= 5) {
        (*calculate[choice])(num, num2);
        printf("%s", "\nEnter a choice: ");
        scanf("%i", &choice);
        printf("%s", "Enter first number: ");
        scanf("%lf", &num);
        printf("%s", "Enter second number: ");
        scanf("%lf", &num2);
    }

    puts("Program exit");

    return 0;
}

void add(double num, double num2)
{
    printf("Addition: %.2lf\n", num + num2);
}
void sub(double num, double num2)
{
    printf("Subraction: %.2lf\n", num - num2);
}
void times(double num, double num2)
{
    printf("Multiplication: %.2lf\n", num * num2);
}
void divide(double num, double num2)
{
    printf("Division: %.2lf\n", (double)num / num2);
}
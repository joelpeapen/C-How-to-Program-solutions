// calculate average miles per gallon
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int counter = 0; // to calculate average
    double gallons = 2, miles = 0, mg = 0, total_mg = 0;

    while (gallons > 1) {
        printf("%s", "\nEnter the gallons used (-1 to end): ");
        scanf("%lf", &gallons);
        if (gallons == -1) {
            break;
        }
        printf("%s", "Enter the miles driven: ");
        scanf("%lf", &miles);
        mg = miles / gallons;
        total_mg += mg;
        printf("The miles/gallon for this tank was %lf\n", mg);
        counter++;
    }

    printf("The overall average miles/gallon was %lf", total_mg / counter);

    return 0;
}

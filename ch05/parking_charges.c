// 5.9 calculate parking charges for customers
#include <stdio.h>
#define SIZE 3

float calculateCharges(float hours) {
    return (hours > 3) ? 2 + (0.5 * (hours - 3)) : 2;
}

int main(void) {
    // enter hours for three customers
    float hours[SIZE], totalHours = 0;
    for (int i = 0; i < SIZE; i++) {
        printf("%s", "Enter hour: ");
        scanf("%f", &hours[i]);
        totalHours += hours[i];
    }

    // calculate charges
    float charges[SIZE], totalCharges = 0;
    for (int i = 0; i < SIZE; i++) {
        charges[i] = calculateCharges(hours[i]);
        totalCharges += charges[i];
    }

    // print table
    printf("\nCar\tHours\tCharge\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%i\t%.2f\t%.2f\n", i + 1, hours[i], charges[i]);
    }
    printf("Total\t%.2f\t%.2f", totalHours, totalCharges);

    return 0;
}

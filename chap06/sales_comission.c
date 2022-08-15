#include <stdio.h>
#define SIZE 9

int main(int argc, char const* argv[])
{
    int numSales = 0;
    printf("%s", "Enter number of sales people: ");
    scanf("%i", &numSales);

    int gross[numSales], salaries[numSales];
    int frequency[SIZE] = { 0 };

    // enter gross sales
    for (size_t i = 0; i < numSales; i++) {
        printf("%s", "Enter gross sales :");
        scanf("%i", &gross[i]);
    }

    // calculate salaries
    for (size_t i = 0; i < numSales; i++) {
        salaries[i] = 200 + (0.09 * gross[i]);
    }

    // print salaries
    for (size_t i = 0; i < numSales; i++) {
        printf("\nSalaries[%zu]: %i", i, salaries[i]);
    }

    // get frequency
    for (size_t i = 0; i < numSales; i++) {
        int salary = (salaries[i] / 100) - 2;
        // check if salary is not out of array bounds
        (salary > SIZE - 1) ? ++frequency[SIZE - 1] : ++frequency[salary];
    }

    // output
    printf("\n%s\t%14s\n", " Range", "Frequency");
    for (size_t i = 0, range = 200; i < SIZE; i++) {
        if (i == SIZE - 1) { // for last range 1000+
            printf("1000+  %14i\n", frequency[i]);
        } else {
            printf("%zu-%zu%14i\n", range, range + 99, frequency[i]);
            range += 100;
        }
    }

    return 0;
}
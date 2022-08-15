// fig06_17.c
// Two-dimensional array manipulations.
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

// function prototypes
void minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
void maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
void average(const int grades[][EXAMS], size_t pupils, size_t tests);
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests);

int main(void)
{
    // initialize student grades for three students (rows)
    int studentGrades[STUDENTS][EXAMS] = { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };
    // output array studentGrades
    void (*processGrades[4])(const int grades[][EXAMS], size_t pupils, size_t tests) = { printArray, minimum, maximum, average };
    int choice = 0;

    printf("Enter a choice: \n");
    puts(" 0  Print the array of grades");
    puts(" 1  Find the minimum grade");
    puts(" 2  Find the maximum grade");
    puts(" 3  Print the average on all tests for each student");
    puts(" 4  End program");
    scanf("%i", &choice);

    while (choice != 4) {
        (*processGrades[choice])(studentGrades, STUDENTS, EXAMS);

        printf("%s", "\nEnter a choice: \n");
        scanf("%i", &choice);
    }

    puts("Program exited");
}

// Find the minimum grade
void minimum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int lowGrade = 100; // initialize to highest possible grade
    // loop through rows of grades
    for (size_t row = 0; row < pupils; ++row) {
        // loop through columns of grades
        for (size_t column = 0; column < tests; ++column) {
            if (grades[row][column] < lowGrade) {
                lowGrade = grades[row][column];
            }
        }
    }
    printf("Minimum grade: %i", lowGrade); // return minimum grade
}

// Find the maximum grade
void maximum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int highGrade = 0; // initialize to lowest possible grade
    // loop through rows of grades
    for (size_t row = 0; row < pupils; ++row) {
        // loop through columns of grades
        for (size_t column = 0; column < tests; ++column) {
            if (grades[row][column] > highGrade) {
                highGrade = grades[row][column];
            }
        }
    }
    printf("Maximum grade: %i", highGrade); // return minimum grade
}

// Determine the average grade for a particular student
void average(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int total = 0; // sum of test grades
    // total all grades for one student
    for (size_t student = 0; student < pupils; student++) {
        for (size_t test = 0; test < tests; ++test) {
            total += grades[student][test];
        }
        printf("Student %zu average: %.3lf: \n", student, (double)total / tests);
    }
}

// Print the array
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    // output column heads
    printf("\t\t [0]  [1]  [2]  [3]");
    // output grades in tabular format
    for (size_t row = 0; row < pupils; ++row) {
        // output label for row
        printf("\nstudentGrades[%zu] ", row);
        // output grades for one student
        for (size_t column = 0; column < tests; ++column) {
            printf("%-5d", grades[row][column]);
        }
    }
}
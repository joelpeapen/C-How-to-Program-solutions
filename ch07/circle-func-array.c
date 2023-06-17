// calculate circumference, area, sphere volume w/ funtion pointers
#include <stdio.h>
#define PI 3.1416

void circle_circum(float radius);
void circle_area(float radius);
void sphere_volume(float radius);

int main(void) {
    void (*calculate[3])(float radius) = { circle_circum, circle_area, sphere_volume };
    int choice = 0;
    float radius = 0;

    printf("%s", "Enter a choice: \n");
    puts(" 0  for circle circumference");
    puts(" 1  for circle area");
    puts(" 2  for sphere volume");
    scanf("%i", &choice);

    printf("%s", "\nEnter radius: ");
    scanf("%f", &radius);

    while (choice != 4 || choice >= 4) {
        (*calculate[choice])(radius);
        printf("%s", "\nEnter a choice: ");
        scanf("%i", &choice);
        if (choice == 4)
            break;
        printf("%s", "Enter radius: ");
        scanf("%f", &radius);
    }

    puts("Program exit");

    return 0;
}

void circle_circum(float radius) {
    printf("\nCircumference: %f\n", 2 * PI * radius);
}
void circle_area(float radius) {
    printf("\nArea: %f\n", PI * radius * radius);
}
void sphere_volume(float radius) {
    float volume = (float)(4 / 3) * PI * radius * radius * radius;
    printf("Volume: %f\n", volume);
}

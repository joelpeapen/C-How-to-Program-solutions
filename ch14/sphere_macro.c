#include <stdio.h>
#define VOL_SPHERE(r) ((4.0 / 3) * 3.14159 * r * r * r)

int main() {
    double radius = 0;
    printf("%s", "Enter radius: ");
    scanf("%lf", &radius);

    printf("%lf", VOL_SPHERE(radius));

    return 0;
}

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    // initialize variables
    int counter = 0, pass = 0, fail = 0, input = 0;

    // input 10 results
    while (counter < 11) {
        printf("%s", "enter result: ");
        scanf("%d", &input);

        // 1 = pass, 2 = fail
        if (input == 1) {
            pass++;
        }
        else {
            fail++;
        }

        counter++;
    }

    // only print if at least one result entered
    if (counter != 0) {
        printf("%d students passed :)\n", pass);
        if (pass > 8) {
            printf("Bonus to the instructor!\n");
        }
        printf("%d students failed :(", fail);
    }

    return 0;
}

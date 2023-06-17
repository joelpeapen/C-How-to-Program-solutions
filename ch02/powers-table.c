#include <stdio.h>

int main(void) {
    puts("number\tsquare\tcube");
    for (int i = 0; i <= 10; i++) {
        printf("%d\t%d\t%d\n", i, i * i, i * i * i);
    }

    return 0;
}

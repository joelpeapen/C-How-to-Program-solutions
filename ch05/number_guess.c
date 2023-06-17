// automated number guessing game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random(int start, int end);

int main(void) {
    srand(time(NULL));
    int guess = 1, start = 0, limit = 0, random = 0, num = 0, again = 0;

    while (1) {
        printf("%s", "Enter start: ");
        scanf("%i", &start);
        printf("%s", "Enter limit: ");
        scanf("%i", &limit);

        printf("\nGuess the number between %i and %i\n", start, limit);

        random = get_random(start, limit);

        while (num != random) {
            printf("Guess %i: ", guess);
            scanf("%i", &num);

            guess++;

            if (num > random) {
                puts("Too high. Try again");
                guess++;
            } else if (num < random) {
                puts("Too low. Try again");
                guess++;
            }
        }

        printf("\nCorrect! %i!", random);
        printf("\nPlay again? [0/1]: ");
        scanf("%i", &again);
        guess = 1;

        if (again != 0)
            exit(0);

        system("clear");
    }
}

int get_random(int start, int end) {
    int num = 0, limit = 0;
    if (start > end) {
        num = end + (rand() % start);
        limit = start;
    } else {
        num = start + (rand() % end);
        limit = end;
    }

    // TODO: fix bug when start close to end rand return higher num
    if (num > limit) {
        printf("ERROR: guess high: %i", num);
        exit(1);
    }
    return num;
}

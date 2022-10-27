// number guessing game
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // for rand()
#include <time.h> // for time()

int get_random(int, int);

int main(void)
{
    srand(time(NULL)); // get random seeds for rand

    int guesses = 1, start = 0, limit = 0, random = 0, num = 0;
    int again = 0;

    while (true) {
        printf("%s", "Enter start: ");
        scanf("%i", &start);
        printf("%s", "Enter limit: ");
        scanf("%i", &limit);

        int random = get_random(start, limit);

        while (num != random) {
            printf("%s (Guess %i): ", "Guess the number", guesses);
            scanf("%i", &num);
            if (num > random) {
                puts("Too high. Try again");
                guesses++;
            } else if (num < random) {
                puts("Too low. Try again");
                guesses++;
            }
        }

        if (num == random)
            puts("\nCorrect!");

        printf("\nPlay again? [0/1]: ");
        scanf("%i", &again);

        if (again != 0)
            exit(0);
    }
}

int get_random(int start, int limit)
{
    return start + (rand() % limit);
}
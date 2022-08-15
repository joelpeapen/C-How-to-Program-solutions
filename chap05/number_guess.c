// number guessing game
#include <stdio.h>
#include <stdlib.h> // for rand()
#include <time.h> // for time()

int get_random(int, int);

int main(void)
{
    srand(time(NULL)); // get random seeds for rand

    int flag = 1, guess = 0, start = 0, limit = 0, random = 0;

    do {

        printf("%s", "Enter start: "); // get range
        scanf("%i", &start);
        printf("%s", "Enter limit:");
        scanf("%i", &limit);

        random = get_random(start, limit); // get random int
        printf("I have a number between %i and %i\n", start, limit);
        printf("%s", "Guess the number: ");
        scanf("%i", &guess);
        // if !correct ask
        if (guess != random) // need if because do while always runs once
        {
            do {
                if (guess > random)
                    printf("Too high. ");
                else if (guess < random)
                    printf("Too low. ");

                printf("%s", "Try again : ");
                scanf("%i", &guess);
            } while (guess != random);
        }

        if (guess == random)
            puts("CORRECT!");

        printf("%s", "\nPlay again? (0 to quit): ");
        scanf("%i", &flag);

    } while (flag != 0);

    return 0;
}

int get_random(int start, int limit)
{
    return start + (rand() % limit);
}
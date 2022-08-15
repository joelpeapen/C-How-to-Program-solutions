// roll dice and count frequencies of their sums
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const* argv[])
{
    srand(time(NULL));
    int sum[12] = { 0 };

    // roll die 36,000 times and count frequency
    for (int i = 0; i < 36000; i++) {
        int faceSum = 1 + (rand() % 6) + (1 + (rand() % 6));
        ++sum[faceSum - 1];
    }

    //  print frequencies of sums
    int total = 0;
    printf("\nRoll\tFrequency");
    for (size_t i = 0; i < 12; i++) {
        printf("\n%zu\t%i", i + 1, sum[i]);
        total += sum[i];
    }

    printf("\nTotal: %i", total); // verify correct frequencies add up to 36K
    return 0;
}
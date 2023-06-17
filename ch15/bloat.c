// program to bloat file with random letters to hide text
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bloat(FILE* in, FILE* out);
char get_random_letter();
void print_file(const char* filename);

char letters[26] = { 'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z' };

int main(int argc, const char* argv[]) {
    srand(time(NULL));

    FILE* readfile = NULL;
    FILE* outfile = NULL;
    int c = 0; // stores char

    if ((readfile = fopen(argv[1], "r")) == NULL) {
        printf("\nCouldn't open file \"%s\"", argv[1]);
        puts("\nUsage: ./bloat infile");
    } else {
        if ((outfile = fopen("bloat.txt", "w")) == NULL) {
            puts("\n Bloat couldn't open.\nUsage: ./bloat infile");
        } else {
            bloat(readfile, outfile);
            system("cat bloat.txt");
        }
    }

    fclose(readfile);
    fclose(outfile);
}

void bloat(FILE* in, FILE* out) {
    int c = 0;
    while (!feof(in)) {
        if ((c = fgetc(in)) == ' ') {
            fputc(get_random_letter(), out);
        } else {
            fputc(c, out);
        }
    }
}

char get_random_letter() {
    static int num = 1;

    int random = 0 + (rand() % 25);

    if (num % 2 == 0) {
        num++;
        return toupper(letters[random]);
    } else {
        num++;
        return letters[random];
    }
}

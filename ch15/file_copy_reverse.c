// 15.7
// reads the first file’s characters one at a time and writes them to the second file in reverse order
#include <stdio.h>

// 1) copy first line and next lines pasted at start of file (reverse_copy)
// 2) copy backwards from end of readFile (backwards_copy)

void backwards_copy(FILE* readFile, const char* filename);
void reverse_copy(FILE* readFile, const char* writeFile);
void print_file(const char* filename);

int main(int argc, char const* argv[]) {
    int choice = 0;
    FILE* readFile = NULL; // file pointer for read
    void (*f[2])(FILE*, const char*) = { reverse_copy, backwards_copy };

    puts("Enter choice:\n"
         "0 reverse_copy\n"
         "1 backwards copy\n"
         "2 to end program");

    do {
        printf("%s", "? ");
        scanf("%i", &choice);
    } while (choice < 0 || choice > 2);

    if ((readFile = fopen(argv[1], "r")) != NULL) {
        // reverse_copy(readFile, argv[2]);
        // backwards_copy(readFile, argv[2]);
        (*f[choice])(readFile, argv[2]);

        fclose(readFile);
        print_file(argv[2]);
    } else {
        printf("File couldn't open");
    }

    puts("End of run");

    return 0;
}

void backwards_copy(FILE* readFile, const char* filename) {
    FILE* outFile = NULL;
    int s = 0; // holds one line from file
    int position = -1; // for some reason must be -1

    // get size of file
    while ((s = fgetc(readFile)) != EOF) {
        position++;
    }
    s = 0;

    printf("\nThis file has %i characters\n", position);

    if ((outFile = fopen(filename, "w")) != NULL) {
        // while not reach start copy chars backwards from end of file
        while (position != -1) {
            fseek(readFile, position--, SEEK_SET);
            s = fgetc(readFile);
            fputc(s, outFile);
        }

        fclose(outFile);
    } else {
        printf("File \"%s\" couldn't open.", filename);
    }
}

// doesn't work
void reverse_copy(FILE* readFile, const char* filename) {
    FILE* outFile = NULL;
    int s = 0; // holds one line from file

    if ((outFile = fopen(filename, "w")) != NULL) {
        // read one char into 's' and write to start of file
        while ((s = fgetc(readFile)) != EOF) {
            rewind(outFile);
            fprintf(outFile, "%c", s);
        }

        fclose(outFile);
    } else {
        printf("File \"%s\" couldn't open", filename);
    }
}

void print_file(const char* filename) {
    FILE* readFile = NULL;
    int c = 0, line = 1;

    printf("\nOpening \"%s\": \n\n", filename);

    if ((readFile = fopen(filename, "r")) != NULL) {

        printf("\t");
        while ((c = fgetc(readFile)) != EOF) {
            if (c != '\n') {
                printf("%c", c);
            } else {
                printf("\n\t%2i| ", line++); // print w/ indents and line numbers
            }
        }

        puts("");
        fclose(readFile);
    } else {
        printf("File \"%s\" couldn\'t open", filename);
    }
}

// deitel 15.7
// reads the first file’s characters one at a time and writes them to the second file in reverse order
#include <stdio.h>
#include <stdlib.h>

void reverse(FILE* readFile, const char* filename);
void print_file(const char* filename);

int main(int argc, char const* argv[]) {
    FILE* readFile = NULL;

    if ((readFile = fopen(argv[1], "r")) != NULL) {
        reverse(readFile, argv[2]);

        fclose(readFile);
        // print_file(argv[2]);
        system("cat reverse.txt");
    } else {
        printf("\nFile couldn't open.\nUsage: ./reverse infile outfile");
    }

    puts("\nEnd of run");

    return 0;
}

void reverse(FILE* readFile, const char* filename) {
    FILE* outFile = NULL;
    int s = 0; // holds one char from file
    int byte = -1; // for some reason must be -1

    // get size of file
    while ((s = fgetc(readFile)) != EOF) {
        byte++;
    }
    s = 0;

    printf("\nInput file is %i bytes\n", byte + 1);

    if ((outFile = fopen(filename, "w")) == NULL) {
        printf("File \"%s\" couldn't open.", filename);
    } else {
        // while not reach start copy chars backwards from end of file
        while (byte != -1) {
            fseek(readFile, byte--, SEEK_SET);
            s = fgetc(readFile);
            fputc(s, outFile);
        }

        fclose(outFile);
    }
}

void print_file(const char* filename) {
    FILE* readFile = NULL;
    int c = 0, line = 1;

    printf("\nOpening \"%s\": \n\n", filename);

    if ((readFile = fopen(filename, "r")) == NULL) {
        printf("File \"%s\" couldn\'t open", filename);
    } else {
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
    }
}

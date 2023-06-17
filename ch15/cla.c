// 15.3
// printing command line arguments
#include <stdio.h>

int main(int argc, char const* argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("command[%i] is %s\n", i, argv[i]);
    }
    return 0;
}

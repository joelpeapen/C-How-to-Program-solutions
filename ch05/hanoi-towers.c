// 5.35 Towers of Hanoi
#include <stdio.h>

void hanoi(int disks, char source, char dest, char temp);
void move(char source, char dest);

int main() {
    int disks = 0;
    char source = 'A', dest = 'C';

    printf("%s", "Enter n disks: ");
    scanf("%i", &disks);

    hanoi(disks, source, dest, 'B');
}

void hanoi(int disks, char source, char dest, char temp) {
    if (disks == 1) {
        move(source, dest);
    } else { // recursive step
        hanoi(disks - 1, source, temp, dest);
        move(source, dest);
        hanoi(disks - 1, temp, dest, source);
    }
}

void move(char source, char dest) {
    printf("\n%c --> %c", source, dest);
}

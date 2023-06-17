// 6.24 Knight's Tour
#include <stdio.h>
#include <stdlib.h>

void move(int board[8][8], size_t row, size_t col, int moveNum);
void print_moves(int moveNum, size_t row, size_t col);
void print_board(int board[8][8]);;
int instructions(void);

int horizontal[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; // 8 move types
int vertical[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
size_t ROW = 3, COL = 3; // current tile
int COUNT = 1; // latest move number

int main (void) {
    int board[8][8] = { { 0 } }; // chessboard
    int moveNum = 0;

    print_board(board);
    puts("\nFILL THE BOARD");

    printf("\n %s", "Enter row start: ");
    scanf("%zu", &ROW);
    printf("\n %s", "Enter column start: ");
    scanf("%zu", &COL);

    board[ROW][COL] = 65; // mark initial tile
    system("clear"); // remove clutter
    system("rm moves.txt"); // remove old file

    print_board(board); // to see progress

    while (COUNT <= 64) { // 64 moves
        moveNum = instructions();

        if (moveNum == -1)
            break;

        move(board, ROW, COL, moveNum);
        system("clear");
        print_board(board); // to see progress
    }

    printf("\nThe knight made %i moves. You need 64 for a full tour", COUNT - 1);

    return 0;
}

void move(int board[8][8], size_t row, size_t col, int moveNum) {
    size_t r = row, c = col;
    r += vertical[moveNum];
    c += horizontal[moveNum]; // get tile number

    if (board[r][c] == 0) { // move if valid tile
        if ((r < 8 || c < 8) && (r >= 0 || c >= 0)) { // check board boundaries
            ROW += vertical[moveNum];
            COL += horizontal[moveNum];

            board[ROW][COL] = COUNT++; // add count to the tile

            printf("\tMove to [%zu][%zu]", ROW, COL);
            print_moves(moveNum, ROW, COL); // to see progress in file
        } else {
            puts("Can't move there. Try again");
        }
    } else {
        puts("\nTaken. Try again");
    }
}

void print_board(int board[8][8]) {
    puts("\n\n\t");
    for (int a = 0; a < 8; a++) {
        printf("  %3i", a);
    }
    puts("");
    for (int a = 0; a < 8; a++) {
        printf(" %4c", '-');
    }
    puts("");

    for (int i = 0; i < 8; i++) {
        printf(" %i|", i);
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 65)
                printf(" %-4i", 0);
            else if (board[i][j] == 0)
                printf(" %-4c", '*');
            else
                printf(" %-4i", board[i][j]);
        }
        puts("\n");
    }
    puts("\n");
}

void print_moves(int moveNum, size_t row, size_t col) {
    FILE* moves = NULL;

    if ((moves = fopen("moves.txt", "a")) != NULL) {
        if (moveNum == 0) {
            fprintf(moves, "%-20s \t[%zu][%zu]\n", "0) left left up", row, col);
        } else if (moveNum == 1) {
            fprintf(moves, "%-20s \t[%zu][%zu]\n", "1) right up up", row, col);
        } else if (moveNum == 2) {
            fprintf(moves, "%-20s \t[%zu][%zu]\n", "2) left up up", row, col);
        } else if (moveNum == 3) {
            fprintf(moves, "%-20s \t[%zu][%zu]\n", "3) up right right", row, col);
        } else if (moveNum == 4) {
            fprintf(moves, "%-20s \t[%zu][%zu]\n", "4) left left down", row, col);
        } else if (moveNum == 5) {
            fprintf(moves, "%-20s \t[%zu][%zu]\n", "5) down down left", row, col);
        } else if (moveNum == 6) {
            fprintf(moves, "%-20s \t[%zu][%zu]\n", "6) down down right", row, col);
        } else if (moveNum == 7) {
            fprintf(moves, "%-20s \t[%zu][%zu]\n", "7) right right down", row, col);
        } else {
            fprintf(moves, "%-20s \t[%zu][%zu]\n", "else", row, col);
        }

        fclose(moves);
    } else {
        puts("File couldn't open");
    }
}

int instructions() {
    int choice = 0;
    printf("%s", "\n 0) -> -> ^"
                 "\t4) <- <- ꣺"
                 "\n 1) -> ^ ^"
                 "\t5) ꣺ ꣺ <-"
                 "\n 2) ^ ^ <-"
                 "\t6) ꣺ ꣺ ->"
                 "\n 3) <- <- ^"
                 "\t7) -> -> ꣺");

    do {
        printf("\n\n %s", "Enter choice (-1 to quit): ");
        scanf("%i", &choice);

        if (choice == -1) return -1;

    } while (choice < 0 || choice > 7);

    return choice;
}

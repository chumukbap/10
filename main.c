
#include <stdio.h>
#include <string.h>

#define MAX_NODES 100

#define SMMNODE_TYPE_LECTURE 0
#define SMMNODE_TYPE_RESTAURANT 1
#define SMMNODE_TYPE_LABORATORY 2
#define SMMNODE_TYPE_HOME 3
#define SMMNODE_TYPE_GOTOLAB 4
#define SMMNODE_TYPE_FOODCHANCE 5
#define SMMNODE_TYPE_FESTIVAL 6

char name[MAX_NODES][100];
int type[MAX_NODES];
int credit[MAX_NODES];
int energy[MAX_NODES];
int board_nr = 0;

void setNode(int i, char *n, int t, int c, int e) {
    strcpy(name[i], n);
    type[i] = t;
    credit[i] = c;
    energy[i] = e;
}

void printNode(int i) {
    printf("Node %d\n", i);
    printf("Name: %s\n", name[i]);
    printf("Type: %d\n", type[i]);
    printf("Credit: %d\n", credit[i]);
    printf("Energy: %d\n", energy[i]);
    printf("--------------------\n");
}

int main(void) {
    FILE *fp;
    char n[100];
    int t, c, e;

    fp = fopen("marbleBoardConfig.txt", "r");

    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    printf("Reading board component...\n");

    while (board_nr < MAX_NODES &&
           fscanf(fp, "%99s %d %d %d",
                  n, &t, &c, &e) == 4) {

        setNode(board_nr, n, t, c, e);
        board_nr++;
    }

    fclose(fp);

    printf("Total number of board nodes : %d\n\n", board_nr);

    for (int i = 0; i < board_nr; i++) {
        printNode(i);
    }

    return 0;
}

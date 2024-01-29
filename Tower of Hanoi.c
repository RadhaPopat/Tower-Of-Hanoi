#include <stdio.h>

#define MAX_DISKS 3

struct pole {
    int stack[MAX_DISKS];
};

struct pole p[3];
int top[3] = {-1, -1, -1};

void fillSrc() {
    p[0].stack[0] = 3;
    p[0].stack[1] = 2;
    p[0].stack[2] = 1;
    top[0] = 2;
}

void push(int x) {
    int pl;
    while (1) {
        printf("Choose pole to push to (0, 1, or 2): ");
        scanf("%d", &pl);
        printf("\n");

        if (pl < 0 || pl > 2) {
            printf("Invalid pole index. Try again.\n");
        } else if (p[pl].stack[top[pl]] > x || p[pl].stack[top[pl]] == 0) {
            top[pl]++;
            p[pl].stack[top[pl]] = x;
            break;
        } else {
            printf("Cannot push here. Try again.\n");
        }
    }
}

int pop() {
    int pl, x;
    while (1) {
        printf("Choose pole to pop from (0, 1, or 2): ");
        scanf("%d", &pl);
        printf("\n");

        if (pl < 0 || pl > 2) {
            printf("Invalid pole index. Try again.\n");
        } else if (top[pl] == -1) {
            printf("Pole empty, cannot pop. Try again.\n");
        } else {
            x = p[pl].stack[top[pl]];
            p[pl].stack[top[pl]] = 0;  // Use 0 to represent an empty slot
            top[pl]--;
            return x;
        }
    }
}

void displaylevel(int level) {
	int i;
    for (i = 0; i < 3; i++) {
        if (p[i].stack[level] == 0) {
            printf("[ ]\t");
        } else {
            printf("[%d]\t", p[i].stack[level]);
        }
    }
    printf("\n");
}

void display() {
	int level;
    printf("Current State of Towers:\n");

    for (level = MAX_DISKS - 1; level >= 0; level--) {
        displaylevel(level);
    }
}

int gameWinCondition() {
    return (p[2].stack[0] == 3 && p[2].stack[1] == 2 && p[2].stack[2] == 1);
}

int main() {
    int win = 0;
    int x;

    fillSrc();
    display();

    printf("Tower of Hanoi\n");
    printf("Objective: Your goal is to insert the numbers into the third pole such that from top to bottom, they are in ascending order\n");
    printf("Rule: You cannot put a greater number above a smaller number at any point in the game\n");
    printf("Good luck!\n");

    while (!win) {
        x = pop();
        push(x);
        win = gameWinCondition();
        display();
    }

    printf("Congratulations, you win!\n");

    return 0;
}


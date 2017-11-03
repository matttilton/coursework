#include <stdio.h>
#include <stdlib.h>

struct Student {
    char *name;
    int id;
    float grade[2];
    char lettergrade;
};

struct Course {
    char *name;
    struct Student *students[40];
};

void printcourse(struct Course C) {
    printf("%s", C.name);
    printf("\n");
    for (int i = 0; i < 40; i++) {
        printf("SID: %d : %s Grade: %c \n", C.students[i] -> id, C.students[i] -> name, C.students[i] -> lettergrade);
    }
}

int main() {
    struct Student s1;
    s1.name = "Kyle";
    s1.id = 10100102;
    s1.grade[0] = 67.4;
    s1.grade[1] = 67.5;
    s1.grade[2] = 75.0;
    s1.lettergrade = 'D';

    struct Course csc222;
    csc222.name = "Systems Prog";
    for (int i = 0; i < 40; i++) {
        csc222.students[i] = NULL;
    }

    csc222.students[0] = &s1;
    printcourse(csc222);
    exit(0);
}
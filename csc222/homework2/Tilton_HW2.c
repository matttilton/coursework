#include <cstdlib>
#include <stdio.h>

long addbyvalue(long num1, long num2) {
    return num1 + num2;
}

void addbyreference(long num1, long num2, long *result) {
    *result = num1 + num2;
}

int main(int argc, char *argv[]) {
    long num1 = atoi(argv[1]);
    long num2 = atoi(argv[2]);
    printf("the sum of %ld and %ld = %ld \n", num1,num2,addbyvalue(num1, num2));
    long result = 0;
    addbyreference(num1, num2, &result);
    printf("the sum of %ld and %ld = %ld \n", num1,num2,result);

    return 0;
}
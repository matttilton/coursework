#include <stdio.h>

int main() {

    //get input from user
    int a;
    printf ("Enter the value of int a: \n");
    scanf ("%d", &a);

    a = a * -1; //convert input to negative of itself
    printf("hex is 0x%x", *(unsigned int*) &a); //cast the int to an unsinged int and display hexadecimal representation
    return 0;
}
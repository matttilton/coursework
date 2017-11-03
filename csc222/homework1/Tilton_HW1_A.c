#include <stdio.h>            // Library for input and output
void swap(short *x, short *y) // passing by reference
{
  short temp; // temporary variable
  //temp = *x;
  *x = *y ^ *x;
  *y = *x ^ *y;
}

int main() {
  // Declaration
  short a, b;
  // Input
  printf("Enter the values of A and B: \n");
  scanf("%hd", &a); // reading value of a
  scanf("%hd", &b); // reading value of b
  swap(&a, &b);     // calling by reference
  // Display
  printf("The value of A = %hd \n", a);
  printf("The value of B = %hd \n", b);
  return 0;
}
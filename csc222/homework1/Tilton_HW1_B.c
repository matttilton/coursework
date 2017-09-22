# include <stdio.h>
typedef unsigned char *ptr_bytes;
void show_int(int x)
{
    ptr_bytes s = (ptr_bytes) &x;
    for(int i=0; i < sizeof(int); i++)
        printf(" %.4x", s[i]);
    printf("\n");
}
int main()
{
    float a;
    printf ("Enter the value of float a: \n");
    scanf ("%a", &a);
    //show_int(a);
    printf("hex is 0x%x", *(unsigned int*) &a); //cast the float to an unsinged int and display hexadecimal representation
    printf("\n");
    return 0;
}
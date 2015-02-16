#include <stdio.h>
void ctest1(int *);
void ctest2(int *);
 
int main(){
    int x;
    int y;
    int z;
    ctest1(&x);
    ctest2(&y);
    z = (x / y);
    printf("%d / %d = %d\n", x, y, z);
    return 0;
}
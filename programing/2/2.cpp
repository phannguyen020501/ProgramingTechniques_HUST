#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    int a=x;
    int b=y;
    int c=z;
    *(&x)=b;
    *(&y)=c;
    *(&z)=a;
}

int main() {
    int x, y, z;
    printf("Phan Ngoc Nguyen-20194134\n");
    scanf("%d %d %d",&x,&y,&z);
    
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}

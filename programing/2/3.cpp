#include <stdio.h>

//# Vi?t hàm get_value
/*****************
# YOUR CODE HERE #
*****************/
int get_value(int x,int a=2,int b=1,int c=0){
	return a*x*x+b*x+c;
}

int main(){
	printf("Phan Ngoc Nguyen-20194134\n");
    int x;
    scanf("%d", &x);
    
    int a = 2; 
    int b = 1; 
    int c = 0; 
    
    scanf("%d %d %d",&a,&b,&c);
    
    
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,*arr;
	scanf("%d", &n);
	
	arr=(int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i); 
	int x=1;
	for( int i=0;i<n;i++){
		while(x<n+1){
			for(int j=i;j<x;j++){
			printf("%d ",arr[j]);
			}
			printf("\n");
			x++;
		}
		x=i+2;
	}
	free(arr);
	return 0;
}

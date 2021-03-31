#include <stdio.h>

void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    for( l=0;l<=(r/2);l++){
 		tmp=arr[l];
 		arr[l]=arr[r-l];
 		arr[r-l]=tmp;
 	}
}
void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    for(l=0;l<=(r/2);l++){
 		tmp=*(arr+l);
 		*(arr+l)=*(arr+r-l);
 		*(arr+r-l)=tmp;
 	}
}

int main(){
	int arr[] = {9, 3, 5, 6, 2, 5};
	reversearray(arr, 6);
	for(int i = 0; i < 6; i++){
		printf("%d ",arr[i]);
	};
	printf("\n");
	int arr2[] = {4, -1, 5, 9};
	ptr_reversearray(arr2, 4);
	for(int i = 0; i < 4; i++){
		printf("%d ",arr2[i]);
	};
}

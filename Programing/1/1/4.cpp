#include <stdio.h>

int counteven(int* arr, int size){
 	int count=0;
 	for(int i=0;i<size;i++){
 	if(arr[i] % 2==0){
 		count++;
 		}
	}
 	return count;
}

int main(){
	int arr[]={1,5,4,8,10,6,7,2};
	printf("%d ",counteven(arr,8));
	return 0;
}

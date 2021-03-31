#include <stdio.h>
#include <stdlib.h>
void allocate_mem(int*** mt,int n){
	*mt = new int*[n];
	for(int i=0;i<n;i++){
		(*mt)[i]=new int[n];
	}
}
void input(int **mt,int n){
 	for(int i=0;i<n;i++){
 		for(int j=0;j<n;j++){
 			scanf("%d",&mt[i][j]);
 		}
 	}
}
void output(int **mt,int n){
 	for(int i=0;i<n;i++){
 		for(int j=0;j<n;j++){
 			printf("%d ",mt[i][j]);
		}
 	printf("\n");
 	}
}

int** sumMt(int** mt1,int** mt2,int n){
	int** sum;
	allocate_mem(&sum,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum[i][j]=mt1[i][j]+mt2[i][j];
		}
	}
	return sum;
}
int** mulMt(int** mt1,int** mt2,int n){
	int** mul;
	allocate_mem(&mul,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mul[i][j]=0;
			for(int k=0;k<n;k++){
				mul[i][j]+=mt1[i][k]*mt2[k][j];
			}
		}
	}
	return mul;
}

void free_mem(int **mt,int n){
	for(int i=0;i<n;i++){
 		free(mt[i]);
 	} 
 	free(mt);
}
int main(){
	int n, **mt1,**mt2;
 	scanf("%d",&n);
	allocate_mem(&mt1,n);
	allocate_mem(&mt2,n);
	input(mt1,n);
	input(mt2,n);
	int **sum=sumMt(mt1,mt2,n);
	output(sum,n);
	int **mul=mulMt(mt1,mt2,n);
	output(mul,n);
	free_mem(mt1,n);
	free_mem(mt2,n);
	free_mem(sum,n);
	free_mem(mul,n);
	return 0;


}

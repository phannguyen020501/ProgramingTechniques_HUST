#include <iostream>


using namespace std;
typedef struct{
	int n;
	int* x;	
} dathuc;

void input(dathuc &A){
	cin >> A.n;
	A.x = new int[A.n+1];
	for(int i=0;i<=A.n;i++){
		cin >> A.x[i];
	}
}
void output(dathuc  &A){
	cout << A.n <<" ";
	for(int i=0;i<=A.n;i++){
		cout<< A.x[i] <<" ";
	} 
}

dathuc mul(dathuc &A,dathuc &B){
	dathuc C;
	C.n=A.n+B.n;
	C.x=new int[C.n+1];
	for(int i=0;i<=C.n;i++){
		C.x[i]=0;
        for(int j=0;j<=A.n;j++)
        if(i>=j && i-j<=B.n) C.x[i]+=A.x[j]*B.x[i-j];
	}
	return C;
}
int xorDt(dathuc &A){
	int result=A.x[0];
	for(int i=1;i<=A.n;i++){
		result=result^A.x[i];
	}
	return result;
}
void deleteDt(dathuc &A){
	delete[] A.x;
}
int main(){
	cout<<"Phan Ngoc Nguyen-20194134"<<endl;
	dathuc A,B,C;
	input(A);
	input(B);
	C=mul(A,B);
	
	cout<<xorDt(C)<<endl;
	deleteDt(A);
	deleteDt(B);
	deleteDt(C);
}

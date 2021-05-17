#include <iostream>

#include <string>
using namespace std;
#define MAX 100 
int n,k;
int mt[31][31];
int m;
int mark[31];
int result;


void TRY(int x,int i){   
    if(x==(k+1)){
           result++;
           return ;
    }
    for(int t=1;t<=n;t++){
        if(mark[t]==0&&mt[i][t]==1){
            mark[t]=1;
            TRY(x+1,t);
            mark[t]=0;
        }
    }
}
int main(){
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
    int d_dau;
    int d_dich ;
    cin>>n>>k;
    cin>> m;
    for(int i=0;i<m;i++){
        cin>> d_dau>> d_dich;
        mt[d_dau][d_dich]=1;
        mt[d_dich][d_dau]=1;
    }
    result=0;
    for(int i=1;i<=n;i++){
           for(int t=1;t<=n;t++) mark[t]=0;
           mark[i]=1;
           TRY(1,i);
    }
    cout<< result/2 ;
}


#include <iostream>
using namespace std;
int n,k1,k2,L=0,Z=0;
int a[201];
void list(int i) {
        if(i>n){
            for(int j =1;j<=n;j++){
                 cout << a[j];       
            }
           cout<<endl;
            return;
        }
        for(int j=0;j<=1;j++){
            if(j==0){
                if(L>0&&L<k1) continue;
                else if(Z+1<2){
                    a[i]=0;
                    int old_L=L;
                    int old_N=Z;
                    Z++;
                    L=0;
                    list(i+1);
                    L=old_L;
                    Z=old_N;

                }
            }else{
                if(i==n&&L+1<k1) continue;
                else if(L<k2){
                   a[i]=1;
                   int old_L=L;
                   int old_N=Z;
                   L++;
                   Z=0;
                   list(i+1);
                   L=old_L;
                   Z=old_N;
                }

            }
        }
    }
int main(){
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
    cin >> n >> k1>>k2;
    list(1);
}

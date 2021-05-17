#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; //# s? thành ph? và ma tr?n chi phí
int cmin = INT_MAX; //# chi phí di l?i nh? nh?t gi?a hai thành ph? khác nhau
int best = INT_MAX; //# t?ng chi phí nh? nh?t c?n tìm, ban d?u d?t b?ng giá tr? vô cùng l?n INT_MAX = 2^31-1
int curr; //# t?ng chi phí t?i th?i di?m hi?n t?i
int mark[MAX]; //# dánh d?u nh?ng thành ph? dã di
int x[MAX]; //# luu gi? các thành ph? dã di


void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

void solution(){
	if((curr + c[x[n]][x[1]]) < best){
		best = curr + c[x[n]][x[1]];
	}
}
//# Thu?t toán quay 
void TRY(int k){
    for(int v = 2; v <= n; v++){
            if(mark[v] != 1){
                x[k] = v;
                mark[v] = 1;
                curr = curr + c[x[k-1]][x[k]];
                if(k == n){
                    solution();
                }else{
                    int gk = curr + (n-k+1)*cmin;
                    if(gk < best)
                        TRY(k+1);
                }
                mark[v] = 0;
                curr = curr - c[x[k-1]][x[k]];
            }
        }
}

int main() {
	cout << "Phan Ngoc Nguyen - 20194134"<< endl;
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

char cal(double a){
    if (a < 4) return 'F';
    else if (a < 5.5) return 'D';
    else if (a < 7) return 'C';
    else if (a < 8.5) return 'B';
    else return 'A';
}

int main(){
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while(n--){
        int a;
        cin >> a;
        if (cal(a) == 'A') {
        	++A; 
		}
        else if (cal(a) == 'B'){
        	 ++B;
		}
        else if (cal(a) == 'C') {
        	++C; 
		}
        else if (cal(a) == 'D') {
        	++D; 
		}
        else if (cal(a) == 'F') {
        	++F;
		}
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}

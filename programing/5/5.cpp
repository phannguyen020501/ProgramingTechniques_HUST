#include <bits/stdc++.h>
using namespace std;

int main(){
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
    int n;
    cin >> n;
    bool found = false;
    while(n--){
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0)){
        	found = true;
			break;	
		}
            
    }
    if (found) cout << "Yes";
    else cout << "No";
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--){
        int k, t;
        cin >> k >> t;
        if(t == 1){
        	while(k--){
            int a;
            cin >> a;
			sum += a;
            ans = max(ans, -sum);
        	}
		}else if(t == -1){
			while(k--){
            int a;
            cin >> a;
			sum -= a;
            ans = max(ans, -sum);
        	}
		}
       
    }
    cout << ans;
}

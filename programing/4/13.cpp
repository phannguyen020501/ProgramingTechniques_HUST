#include <bits/stdc++.h>

using namespace std;
int countSub(int arr[], int n){
	map<int, int> mp;
	int count = 0;
	int sum = 0;
	for(int i = 0; i < n; i ++){
		sum += arr[i];
		//sum = 0 -> equal;
		if(sum == 0){
			count++;
		}
		if(mp[sum]){
			count += mp[sum];
		}
		if(mp[sum] == 0){
			mp[sum] = 1;
		}else{
			mp[sum] ++ ;
		}
	
	}
	return count;
}



int main(){
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
	string s;
	cin >> s ;
	
	int n = s.length();
	int arr[n];
	
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			arr[i] = 1;
		}else if(s[i] == '0'){
			arr[i] = -1;
		}
	}
	
	cout << countSub(arr,n);
	return 1;
}

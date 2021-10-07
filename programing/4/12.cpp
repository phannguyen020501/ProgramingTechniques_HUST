#include<bits/stdc++.h> 
#include<queue>
using namespace std;
#define Max 1000000
int arr[Max];
stack<pair<int,int>> l_stack,r_stack;
int leftNum[Max],rightNum[Max];
int main(){
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
	int n;
	int maxp=0;
	cin>> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	r_stack.push({-1,n+1});
    for(int i=n-1;i>=0;--i){
        while(arr[i]<=r_stack.top().first) r_stack.pop();
        rightNum[i]=r_stack.top().second-1;
        r_stack.push({arr[i],i});
    }
    l_stack.push({-1,0});
    for(int i=0;i<n;++i){
        while(arr[i]<=l_stack.top().first) l_stack.pop();
        leftNum[i]=l_stack.top().second+1;
        l_stack.push({arr[i],i});
    }
    for(int i=0;i<n;++i){
        maxp=max(maxp,(rightNum[i]-leftNum[i]+1)*arr[i]);
    }
    cout<< maxp;
    return 0;
}

#include<bits/stdc++.h>
#include<queue>
using namespace std;
static long s,n;
// s la so linh
//n la so doan tuong thanh
static priority_queue<pair<long,long>> card;
int main(){
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
	long a,k;
	long result=0;

	cin>> n >> s;
	int arr[n+1][2]; //luu lai cac gia tri cua a va k

	
	for(int i=0;i<n;i++){
		cin >> a >>k ;
		arr[i][0]=a;
		arr[i][1]=k;
		if(a<k) card.push({ a,i});
		else card.push({k,i});
	}

	while(s>0){
		long index=card.top().second;
		if(arr[index][0]- arr[index][1] >=0)
			arr[index][0]-=arr[index][1];
		else arr[index][0]=0;
		card.pop();
		s--;
		if(arr[index][0] < arr[index][1])
			card.push({arr[index][0],index});
		else card.push({arr[index][1],index}) ;
	}
	while (!card.empty()){
		long index= card.top().second;
		result+=arr[index][0];
	//	cout<<card.top().first<<" \t "<< card.top().second<<endl;
		card.pop();
	}
	cout<< result;
}

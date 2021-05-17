#include<bits/stdc++.h>
using namespace std;
#define LL long long int
int n,r, minCost = INT_MAX,tempSum,Ans;
vector<vector<int> > cust;
int	 c[1005][1005];
bool visited[1005];
int best=0;

void TSP(vector<int > customer,int prev,int order){
	int len = (int) customer.size();
	for (int k = 1;k<len-1;++k){
		if (!visited[customer[k]]&&c[prev][customer[k]]!=0){
			tempSum += c[prev][customer[k]];
			visited[customer[k]] = true;
			if (order==len-2&&c[customer[k]][customer.back()]!=0){
				Ans = min(Ans,tempSum + c[customer[k]][customer[len-1]]);
				best=tempSum + c[customer[k]][customer[len-1]];
			}
			else{
				if (tempSum + (len-order-1)*minCost < Ans){
					TSP(customer,customer[k],order+1);
				}
			}
			tempSum -= c[prev][customer[k]];
			visited[customer[k]]= false;
		}
	}
}

main(){	
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
	cin >> n >> r;
	cust.resize(r);
	for (int i = 1;i<=n;++i){
		for (int j = 1;j<=n;++j){
			cin >> c[i][j];
			if (c[i][j]!=0) minCost = min(minCost,c[i][j]);
		}
	}
	getchar();
	for (int i = 0;i<r;++i){
   		string line;
   		getline(cin,line);
      	istringstream is(line);
     	cust[i] = (vector<int>(istream_iterator<int>(is), istream_iterator<int>()));
	}
	for (int i = 0;i<r;++i){
		tempSum = 0; Ans = INT_MAX;
		TSP(cust[i],(cust[i]).at(0),1);
		cout << (Ans%INT_MAX) << endl;
	
	}

}

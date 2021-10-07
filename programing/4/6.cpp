#include<bits/stdc++.h>

using namespace std;

void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> was(adj.size());
    Q.push(1); // B?t d?u t? d?nh s? 1
    
    was[1] = true;
    
    while(!Q.empty()){
    	int u = Q.front();
    	Q.pop();
    	cout << u << endl;
    	for(int v : adj[u]){
    		if(!was[v]){
    			was[v] = true;
    			Q.push(v);
			}
		}
	}
	cout << endl;
}

int main(){
	cout << "Phan Ngoc Nguyen - 20194134 " << endl;
	int n = 7;
vector< list<int> > adj;
adj.resize(n + 1);
adj[1].push_back(2);
adj[2].push_back(4);
adj[1].push_back(3);
adj[3].push_back(4);
adj[3].push_back(5);
adj[5].push_back(2);
adj[2].push_back(7);
adj[6].push_back(7);
bfs(adj);
}

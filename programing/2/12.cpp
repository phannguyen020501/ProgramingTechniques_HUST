#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

typedef struct ds{
	int key;
	int value;
} ds;


int main(){
	printf("Phan Ngoc Nguyen-20194134\n");
	vector<ds> list;
	ds x;
	while (cin >> x.key >>x.value)
	{
		list.push_back(x);
	}
	sort(list.begin(),list.end(),[](ds a, ds b){
		if(a.value != b.value) return a.value > b.value;
		else{
			return a.key >= b.key;
		}	
	});
	
	for(ds a: list){
		cout<<a.key<<" "<<a.value<<endl;
	}
}

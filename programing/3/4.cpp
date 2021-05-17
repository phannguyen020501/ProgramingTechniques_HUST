#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# m?ng ghi nh? l?i gi?i các bài toán con dã du?c gi?i

void init(){
    memset(mem, -1, sizeof(mem));
}

//# Quy ho?ch d?ng, 
//# Hàm lis(i) tr? v? d? dài dãy con tang dài nh?t k?t thúc b?i a[i]
int lis(int i) {
    if(i == -1){
    	return 0;
	}
	if(mem[i] != -1){
		return mem[i];
	}
	mem[i] = 1;
	for(int j = 0; j < i; j++){
		if(a[j] < a[i]){
			mem[i] = max(mem[i], lis(j) + 1);
		}
	}
	return mem[i];
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}

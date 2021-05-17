#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int sum(vector<int> x){
    int sum=0;
    for(int it:x){
        sum+=it;
    }
    return sum;
}

int main() {
	printf("Phan Ngoc Nguyen-20194134\n");
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
    auto sortRule=[] (vector<int> const& x1,vector<int> const& x2){
        return sum(x1) > sum(x2);
    };

    std::sort(a.begin(),a.end(),sortRule);

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}

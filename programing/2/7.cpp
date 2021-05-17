#include <iostream>
using namespace std;

template <typename T>
T arr_sum(T a[],int size_a,T b[],int size_b){
	T sum=0;
	for(int i=0;i<size_a;i++){
		sum+=a[i];
	}
	for(int j=0;j<size_b;j++){
		sum+=b[j];
	}
	return sum;
}

int main() {
	printf("Phan Ngoc Nguyen-20194134\n");
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}

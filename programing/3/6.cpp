#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){
    while(a*b != 0){
    	if(a > b){
    		a = a % b;
		}else{
			b = b % a;
		}
	}
	return a + b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}

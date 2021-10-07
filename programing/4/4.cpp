#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
	a.erase(remove_if(a.begin(), a.end(), [] (int x ){
		return x % 2 == 0;
	}), a.end());
}

void sort_decrease(vector<int> &a) {
	sort(a.rbegin(), a.rend());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
//	int lena = a.size();
//	int lenb = b.size();
//	std::vector<int> c;
//	int i = 0, j = 0;
//	while(i < lena && j < lenb){
//		if(a[i] > b[j]){
//			c.push_back(a[i]);
//			i++;
//		}else if(b[j] > a[i]){
//			c.push_back(b[j]);
//			j++;
//		}else{
//			c.push_back(a[i]);
//			c.push_back(b[j]);
//			i++;
//			j++;
//		}
//	}
//	if(i < lena){
//		while(i < lena){
//			c.push_back(a[i]);
//			i++;
//		}
//			
//	}else if(j < lenb){
//		while(j < lenb){
//			c.push_back(b[j]);
//			j++;
//		}
//	}
//   	return c;
	vector<int> c;
	merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c), greater<int>());
	return c;
}

int main() {
	cout << "Phan Ngoc Nguyen - 20194134" << endl;
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}

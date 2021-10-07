 #include <iostream>
 #include <cmath>
 #include <iomanip>
 #include <utility>
 using namespace std;
 using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    double s;
    s=0.5*abs((c.first - a.first)*(b.second - a.second) - (b.first - a.first)*(c.second - a.second));
    return s;
}

 int main() {
 	 cout << "Phan Ngoc Nguyen - 20194134" << endl;
     cout << setprecision(2) << fixed;
     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
     return 0;
 }

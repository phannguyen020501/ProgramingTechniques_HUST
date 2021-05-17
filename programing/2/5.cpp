#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    Complex c;
    c.real=a.real+b.real;
    c.imag=a.imag+b.imag;
    return c;
}

Complex operator - (Complex a, Complex b) {
    Complex c;
    c.real=a.real-b.real;
    c.imag=a.imag-b.imag;
    return c;
}

Complex operator * (Complex a, Complex b) {
    Complex c;
    c.real=a.real*b.real-a.imag*b.imag;
    c.imag=a.real*b.imag+a.imag*b.real;
    return c;
}

Complex operator / (Complex a, Complex b) {
    Complex c;
    c.real=(a.real*b.real+a.imag*b.imag)/(b.real*b.real+b.imag*b.imag);
    c.imag=(b.real*a.imag-a.real*b.imag)/(b.real*b.real+b.imag*b.imag);
    return c;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
	printf("Phan Ngoc Nguyen-20194134\n");
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}

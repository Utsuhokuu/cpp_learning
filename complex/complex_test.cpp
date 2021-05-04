#include <iostream>
#include "complex.h"

using namespace std;

int main() {
	complex c1 (2, 1);
	complex c2 (4, 2);
	complex c3 (c1);
	complex c4 = c2; 
	
	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c1.imag() << endl;
	cout << real(c2) << endl;
	
	cout << c1 + c2 << endl;
	cout << c1 - c2 << endl;
	cout << c1 * c2 << endl;
	cout << c1 / c2 << endl;
	
	cout << c1 + 2 << endl;
	cout << 2 - c1 << endl;
	cout << c1 * 2 << endl;
	cout << c1 / 2 << endl;
	
	cout << +c1 << endl;
	cout << -c2 << endl;
	
	cout << (c1 += c2) << endl;
	cout << (c1 -= c2) << endl;
	cout << (c1 *= c2) << endl;
	cout << (c1 /= c2) << endl;
	
	cout << (c1 == c2) << endl;
	cout << (c1 != c2) << endl;
	
	cout << polar(6, 3) << endl;
	cout << conj(c1) << endl;
	cout << norm(c1) << endl;
	
	return 0;
}

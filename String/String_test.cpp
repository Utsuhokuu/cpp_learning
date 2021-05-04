#include <iostream>
#include "String.h"

using namespace std;

int main() {
	String s1("Hello");
	String s2("World");
	
	cout << s1 << endl;
	cout << s2 << endl;
	
	String s3(s1);
	String s4 = s2;
	
	cout << s3 << endl;
	cout << s4 << endl;
	
	String s5 = s3 = s2;
	
	cout << s5 << ' ' << s3 << endl;
}

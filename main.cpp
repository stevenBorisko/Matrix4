#include "Matrix4.hpp"

#include <iostream>

using namespace std;

int main() {
	double data[16];
	for(size_t i = 0;i < 16;++i)
		data[i] = (double)(i+1);

	Matrix4 a(data);

	cout << a << endl;
	//a *= Matrix4();
	a >>= Matrix4::M_scale(2,3,5);
	cout << a << endl;
}

#include "Matrix4.hpp"

#include <iostream>

using namespace std;

int main() {
	double matData[16];
	for(size_t i = 0;i < 16;++i)
		matData[i] = (double)(i+1);

	Matrix4 a(matData);

	cout << "a: " << a << endl;

	double vecData[4];
	for(size_t i = 0;i < 4;++i)
		vecData[i] = (double)(i << 1);

	Vector4 b(vecData);

	cout << "b: " << b << endl;

	b.scale(2);
	cout << b << endl;
}

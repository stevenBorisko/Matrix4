#include <Matrix4.hpp>

Matrix4::Matrix4() {
	memset(this->data, 0, MATRIX_DATA_SIZE);
	this->data[0] = 1.0;
	this->data[5] = 1.0;
	this->data[10] = 1.0;
	this->data[15] = 1.0;
}

Matrix4::Matrix4(const Matrix4& rhs) {
	if(this == &rhs) return;
	memcpy(this->data, rhs.data, MATRIX_DATA_SIZE);
}

Matrix4::Matrix4(const double newData[ELEMENT_COUNT]) {
	memcpy(this->data, newData, MATRIX_DATA_SIZE);
}

Matrix4::~Matrix4() { }

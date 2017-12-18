#include "Matrix4.hpp"

// CONSTRUCTORS

Vector4::Vector4() {
	memset(this->data, 0, VECTOR_DATA_SIZE);
}

Vector4::Vector4(const Vector4& rhs) {
	if(this == &rhs) return;
	memcpy(this->data, rhs.data, VECTOR_DATA_SIZE);
}

Vector4::Vector4(const double newData[DIMENSION]) {
	memcpy(this->data, newData, VECTOR_DATA_SIZE);
}

Vector4::~Vector4() { }

#include <Matrix4.hpp>

// ASSIGNMENT

Matrix4& Matrix4::operator=(const Matrix4& rhs) {
	if(this == &rhs) return *this;
	memcpy(this->data, rhs.data, MATRIX_DATA_SIZE);
	return *this;
}

double* Matrix4::operator[](const size_t& rIndex) const {
	return (double*)((void*)this->data) + (rIndex << 2);
}

double* Matrix4::operator[](const size_t& rIndex) {
	return (data + (rIndex << 2));
}

// BINARY

Matrix4 Matrix4::operator+(const Matrix4& rhs) const {
	Matrix4 ret(*this);
	ret += rhs;
	return ret;
}

Matrix4 Matrix4::operator-(const Matrix4& rhs) const {
	Matrix4 ret(*this);
	ret -= rhs;
	return ret;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs) const {
	Matrix4 ret(*this);
	ret *= rhs;
	return ret;
}

Vector4 Matrix4::operator*(const Vector4& rhs) const {
	Vector4 ret;
	ret[0] = rhs[0] * this->data[0]
		+ rhs[1] * this->data[1]
		+ rhs[2] * this->data[2]
		+ rhs[3] * this->data[3];
	ret[1] = rhs[0] * this->data[4]
		+ rhs[1] * this->data[5]
		+ rhs[2] * this->data[6]
		+ rhs[3] * this->data[7];
	ret[2] = rhs[0] * this->data[8]
		+ rhs[1] * this->data[9]
		+ rhs[2] * this->data[10]
		+ rhs[3] * this->data[11];
	ret[3] = rhs[0] * this->data[12]
		+ rhs[1] * this->data[13]
		+ rhs[2] * this->data[14]
		+ rhs[3] * this->data[15];
	return ret;
}

Matrix4 Matrix4::operator*(const double& rhs) const {
	Matrix4 ret(*this);
	ret *= rhs;
	return ret;
}

Matrix4 Matrix4::operator<<(const Matrix4& rhs) const {
	return (*this * rhs);
}

Vector4 Matrix4::operator<<(const Vector4& rhs) const {
	return (*this * rhs);
}

Matrix4 Matrix4::operator>>(const Matrix4& rhs) const {
	return (*this * rhs);
}

Vector4 Matrix4::operator>>(const Vector4& rhs) const {
	return (*this * rhs);
}


// BINARY ASSIGN

Matrix4& Matrix4::operator+=(const Matrix4& rhs) {
	this->data[0] += rhs.data[0];
	this->data[1] += rhs.data[1];
	this->data[2] += rhs.data[2];
	this->data[3] += rhs.data[3];
	this->data[4] += rhs.data[4];
	this->data[5] += rhs.data[5];
	this->data[6] += rhs.data[6];
	this->data[7] += rhs.data[7];
	this->data[8] += rhs.data[8];
	this->data[9] += rhs.data[9];
	this->data[10] += rhs.data[10];
	this->data[11] += rhs.data[11];
	this->data[12] += rhs.data[12];
	this->data[13] += rhs.data[13];
	this->data[14] += rhs.data[14];
	this->data[15] += rhs.data[15];
	return *this;
}

Matrix4& Matrix4::operator-=(const Matrix4& rhs) {
	this->data[0] -= rhs.data[0];
	this->data[1] -= rhs.data[1];
	this->data[2] -= rhs.data[2];
	this->data[3] -= rhs.data[3];
	this->data[4] -= rhs.data[4];
	this->data[5] -= rhs.data[5];
	this->data[6] -= rhs.data[6];
	this->data[7] -= rhs.data[7];
	this->data[8] -= rhs.data[8];
	this->data[9] -= rhs.data[9];
	this->data[10] -= rhs.data[10];
	this->data[11] -= rhs.data[11];
	this->data[12] -= rhs.data[12];
	this->data[13] -= rhs.data[13];
	this->data[14] -= rhs.data[14];
	this->data[15] -= rhs.data[15];
	return *this;
}

Matrix4& Matrix4::operator*=(const Matrix4& rhs) {
	double temp[16];

	// column 0
	temp[0] = this->data[0] * rhs.data[0]
		+ this->data[1] * rhs.data[4]
		+ this->data[2] * rhs.data[8]
		+ this->data[3] * rhs.data[12];
	temp[4] = this->data[4] * rhs.data[0]
		+ this->data[5] * rhs.data[4]
		+ this->data[6] * rhs.data[8]
		+ this->data[7] * rhs.data[12];
	temp[8] = this->data[8] * rhs.data[0]
		+ this->data[9] * rhs.data[4]
		+ this->data[10] * rhs.data[8]
		+ this->data[11] * rhs.data[12];
	temp[12]= this->data[12] * rhs.data[0]
		+ this->data[13] * rhs.data[4]
		+ this->data[14] * rhs.data[8]
		+ this->data[15] * rhs.data[12];

	// column 1
	temp[1] = this->data[0] * rhs.data[1]
		+ this->data[1] * rhs.data[5]
		+ this->data[2] * rhs.data[9]
		+ this->data[3] * rhs.data[13];
	temp[5] = this->data[4] * rhs.data[1]
		+ this->data[5] * rhs.data[5]
		+ this->data[6] * rhs.data[9]
		+ this->data[7] * rhs.data[13];
	temp[9] = this->data[8] * rhs.data[1]
		+ this->data[9] * rhs.data[5]
		+ this->data[10] * rhs.data[9]
		+ this->data[11] * rhs.data[13];
	temp[13]= this->data[12] * rhs.data[1]
		+ this->data[13] * rhs.data[5]
		+ this->data[14] * rhs.data[9]
		+ this->data[15] * rhs.data[13];

	// column 2
	temp[2] = this->data[0] * rhs.data[2]
		+ this->data[1] * rhs.data[6]
		+ this->data[2] * rhs.data[10]
		+ this->data[3] * rhs.data[14];
	temp[6] = this->data[4] * rhs.data[2]
		+ this->data[5] * rhs.data[6]
		+ this->data[6] * rhs.data[10]
		+ this->data[7] * rhs.data[14];
	temp[10]= this->data[8] * rhs.data[2]
		+ this->data[9] * rhs.data[6]
		+ this->data[10] * rhs.data[10]
		+ this->data[11] * rhs.data[14];
	temp[14]= this->data[12] * rhs.data[2]
		+ this->data[13] * rhs.data[6]
		+ this->data[14] * rhs.data[10]
		+ this->data[15] * rhs.data[14];

	// column 3
	temp[3] = this->data[0] * rhs.data[3]
		+ this->data[1] * rhs.data[7]
		+ this->data[2] * rhs.data[11]
		+ this->data[3] * rhs.data[15];
	temp[7] = this->data[4] * rhs.data[3]
		+ this->data[5] * rhs.data[7]
		+ this->data[6] * rhs.data[11]
		+ this->data[7] * rhs.data[15];
	temp[11]= this->data[8] * rhs.data[3]
		+ this->data[9] * rhs.data[7]
		+ this->data[10] * rhs.data[11]
		+ this->data[11] * rhs.data[15];
	temp[15]= this->data[12] * rhs.data[3]
		+ this->data[13] * rhs.data[7]
		+ this->data[14] * rhs.data[11]
		+ this->data[15] * rhs.data[15];

	memcpy(this->data, temp, MATRIX_DATA_SIZE);

	return *this;
}

Matrix4& Matrix4::operator*=(const double& rhs) {
	this->data[0] *= rhs;
	this->data[1] *= rhs;
	this->data[2] *= rhs;
	this->data[3] *= rhs;
	this->data[4] *= rhs;
	this->data[5] *= rhs;
	this->data[6] *= rhs;
	this->data[7] *= rhs;
	this->data[8] *= rhs;
	this->data[9] *= rhs;
	this->data[10] *= rhs;
	this->data[11] *= rhs;
	this->data[12] *= rhs;
	this->data[13] *= rhs;
	this->data[14] *= rhs;
	this->data[15] *= rhs;
	return *this;
}

Matrix4& Matrix4::operator<<=(const Matrix4& rhs) {
	(*this) *= rhs;
	return *this;
}

Matrix4& Matrix4::operator>>=(const Matrix4& rhs) {
	double temp[16];

	// column 0
	temp[0] = rhs.data[0] * this->data[0]
		+ rhs.data[1] * this->data[4]
		+ rhs.data[2] * this->data[8]
		+ rhs.data[3] * this->data[12];
	temp[4] = rhs.data[4] * this->data[0]
		+ rhs.data[5] * this->data[4]
		+ rhs.data[6] * this->data[8]
		+ rhs.data[7] * this->data[12];
	temp[8] = rhs.data[8] * this->data[0]
		+ rhs.data[9] * this->data[4]
		+ rhs.data[10] * this->data[8]
		+ rhs.data[11] * this->data[12];
	temp[12]= rhs.data[12] * this->data[0]
		+ rhs.data[13] * this->data[4]
		+ rhs.data[14] * this->data[8]
		+ rhs.data[15] * this->data[12];

	// column 1
	temp[1] = rhs.data[0] * this->data[1]
		+ rhs.data[1] * this->data[5]
		+ rhs.data[2] * this->data[9]
		+ rhs.data[3] * this->data[13];
	temp[5] = rhs.data[4] * this->data[1]
		+ rhs.data[5] * this->data[5]
		+ rhs.data[6] * this->data[9]
		+ rhs.data[7] * this->data[13];
	temp[9] = rhs.data[8] * this->data[1]
		+ rhs.data[9] * this->data[5]
		+ rhs.data[10] * this->data[9]
		+ rhs.data[11] * this->data[13];
	temp[13]= rhs.data[12] * this->data[1]
		+ rhs.data[13] * this->data[5]
		+ rhs.data[14] * this->data[9]
		+ rhs.data[15] * this->data[13];

	// column 2
	temp[2] = rhs.data[0] * this->data[2]
		+ rhs.data[1] * this->data[6]
		+ rhs.data[2] * this->data[10]
		+ rhs.data[3] * this->data[14];
	temp[6] = rhs.data[4] * this->data[2]
		+ rhs.data[5] * this->data[6]
		+ rhs.data[6] * this->data[10]
		+ rhs.data[7] * this->data[14];
	temp[10]= rhs.data[8] * this->data[2]
		+ rhs.data[9] * this->data[6]
		+ rhs.data[10] * this->data[10]
		+ rhs.data[11] * this->data[14];
	temp[14]= rhs.data[12] * this->data[2]
		+ rhs.data[13] * this->data[6]
		+ rhs.data[14] * this->data[10]
		+ rhs.data[15] * this->data[14];

	// column 3
	temp[3] = rhs.data[0] * this->data[3]
		+ rhs.data[1] * this->data[7]
		+ rhs.data[2] * this->data[11]
		+ rhs.data[3] * this->data[15];
	temp[7] = rhs.data[4] * this->data[3]
		+ rhs.data[5] * this->data[7]
		+ rhs.data[6] * this->data[11]
		+ rhs.data[7] * this->data[15];
	temp[11]= rhs.data[8] * this->data[3]
		+ rhs.data[9] * this->data[7]
		+ rhs.data[10] * this->data[11]
		+ rhs.data[11] * this->data[15];
	temp[15]= rhs.data[12] * this->data[3]
		+ rhs.data[13] * this->data[7]
		+ rhs.data[14] * this->data[11]
		+ rhs.data[15] * this->data[15];

	memcpy(this->data, temp, MATRIX_DATA_SIZE);

	return *this;
}

// UNARY

Matrix4 Matrix4::operator-() const {
	Matrix4 ret(*this);
	ret.negate();
	return ret;
}

Matrix4 Matrix4::operator~() const {
	Matrix4 ret(*this);
	ret.transpose();
	return ret;
}

// RELATIONAL

bool Matrix4::operator==(const Matrix4& rhs) const {
	bool equal = true;
	equal &= (this->data[0] == rhs.data[0]);
	equal &= (this->data[1] == rhs.data[1]);
	equal &= (this->data[2] == rhs.data[2]);
	equal &= (this->data[3] == rhs.data[3]);
	equal &= (this->data[4] == rhs.data[4]);
	equal &= (this->data[5] == rhs.data[5]);
	equal &= (this->data[6] == rhs.data[6]);
	equal &= (this->data[7] == rhs.data[7]);
	equal &= (this->data[8] == rhs.data[8]);
	equal &= (this->data[9] == rhs.data[9]);
	equal &= (this->data[10] == rhs.data[10]);
	equal &= (this->data[11] == rhs.data[11]);
	equal &= (this->data[12] == rhs.data[12]);
	equal &= (this->data[13] == rhs.data[13]);
	equal &= (this->data[14] == rhs.data[14]);
	equal &= (this->data[15] == rhs.data[15]);
	return equal;
}

bool Matrix4::operator!=(const Matrix4& rhs) const {
	return !(*this == rhs);
}

// OSTREAM

std::ostream& operator<<(std::ostream& os, const Matrix4& rhs) {
	return os << "[ <Matrix4>\n"
		<< "\t[ " << rhs.data[0] << ", "
		<< rhs.data[1] << ", "
		<< rhs.data[2] << ", "
		<< rhs.data[3] << " ],\n"
		<< "\t[ " << rhs.data[4] << ", "
		<< rhs.data[5] << ", "
		<< rhs.data[6] << ", "
		<< rhs.data[7] << " ],\n"
		<< "\t[ " << rhs.data[8] << ", "
		<< rhs.data[9] << ", "
		<< rhs.data[10] << ", "
		<< rhs.data[11] << " ],\n"
		<< "\t[ " << rhs.data[12] << ", "
		<< rhs.data[13] << ", "
		<< rhs.data[14] << ", "
		<< rhs.data[15] << " ]\n"
	<< "] </Matrix4>";
}

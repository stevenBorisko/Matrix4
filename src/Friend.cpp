#include <Matrix4.hpp>

Matrix4 M_transpose(const Matrix4& rhs) {
	Matrix4 ret(rhs);
	ret.transpose();
	return ret;
}

Matrix4 M_negative(const Matrix4& rhs) {
	Matrix4 ret(rhs);
	ret.negate();
	return ret;
}

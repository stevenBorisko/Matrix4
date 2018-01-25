#include "Matrix4.hpp"

void Matrix4::scale(const double& s) {
	this->data[0] *= s;
	this->data[1] *= s;
	this->data[2] *= s;
	this->data[3] *= s;

	this->data[4] *= s;
	this->data[5] *= s;
	this->data[6] *= s;
	this->data[7] *= s;

	this->data[8] *= s;
	this->data[9] *= s;
	this->data[10] *= s;
	this->data[11] *= s;
}

void Matrix4::scale(const double& x, const double& y, const double& z) {
	this->data[0] *= x;
	this->data[1] *= x;
	this->data[2] *= x;
	this->data[3] *= x;

	this->data[4] *= y;
	this->data[5] *= y;
	this->data[6] *= y;
	this->data[7] *= y;

	this->data[8] *= z;
	this->data[9] *= z;
	this->data[10] *= z;
	this->data[11] *= z;
}

void Matrix4::scaleX(const double& s) {
	this->data[0] *= s;
	this->data[1] *= s;
	this->data[2] *= s;
	this->data[3] *= s;
}

void Matrix4::scaleY(const double& s) {
	this->data[4] *= s;
	this->data[5] *= s;
	this->data[6] *= s;
	this->data[7] *= s;
}

void Matrix4::scaleZ(const double& s) {
	this->data[8] *= s;
	this->data[9] *= s;
	this->data[10] *= s;
	this->data[11] *= s;
}

// TRANSLATION

void Matrix4::translate(const double& x, const double& y, const double& z) {
	this->data[3] += x;
	this->data[7] += y;
	this->data[11] += z;
}

void Matrix4::translateX(const double& t) {
	this->data[3] += t;
}

void Matrix4::translateY(const double& t) {
	this->data[7] += t;
}

void Matrix4::translateZ(const double& t) {
	this->data[11] += t;
}

// ROTATION

void Matrix4::rotate(
	const double& r,
	const double& x,
	const double& y,
	const double& z
) {
	(*this) >>= Matrix4::M_rotate(r,x,y,z);
}

void Matrix4::rotateX(const double& r) {
	(*this) >>= Matrix4::M_rotateX(r);
}

void Matrix4::rotateY(const double& r) {
	(*this) >>= Matrix4::M_rotateY(r);
}

void Matrix4::rotateZ(const double& r) {
	(*this) >>= Matrix4::M_rotateZ(r);
}

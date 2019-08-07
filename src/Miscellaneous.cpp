#include <Matrix4.hpp>

void Matrix4::transpose() {
	double temp;

	// row0
	temp = this->data[1];
	this->data[1] = this->data[4];
	this->data[4] = temp;

	temp = this->data[2];
	this->data[2] = this->data[8];
	this->data[8] = temp;

	temp = this->data[3];
	this->data[3] = this->data[12];
	this->data[12] = temp;

	// row1
	temp = this->data[6];
	this->data[6] = this->data[9];
	this->data[9] = temp;

	temp = this->data[7];
	this->data[7] = this->data[13];
	this->data[13] = temp;

	// row2
	temp = this->data[11];
	this->data[11] = this->data[14];
	this->data[14] = temp;
}

void Matrix4::negate() {
	this->data[0] = -this->data[0];
	this->data[1] = -this->data[1];
	this->data[2] = -this->data[2];
	this->data[3] = -this->data[3];
	this->data[4] = -this->data[4];
	this->data[5] = -this->data[5];
	this->data[6] = -this->data[6];
	this->data[7] = -this->data[7];
	this->data[8] = -this->data[8];
	this->data[9] = -this->data[9];
	this->data[10] = -this->data[10];
	this->data[11] = -this->data[11];
	this->data[12] = -this->data[12];
	this->data[13] = -this->data[13];
	this->data[14] = -this->data[14];
	this->data[15] = -this->data[15];
}

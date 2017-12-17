#ifndef MATRIX4_H
#define MATRIX4_H

#include <iostream>
#include <cstring>
#include <cmath>

#define DOUBLE_SIZE sizeof(double)
#define DIMENSION 4
#define ELEMENT_COUNT (DIMENSION * DIMENSION)
// number of bytes in the Matrix variable data
#define MATRIX_DATA_SIZE (DOUBLE_SIZE * ELEMENT_COUNT)
#define VECTOR_DATA_SIZE (DOUBLE_SIZE * DIMENSION)

struct Vector4;

/*
Homogeneous Matrix struct designed for graphics processing
Pretty much all loops are unrolled for max performance
*/
struct Matrix4 {

	// Constructors
	// makes an identity matrix
	Matrix4();
	Matrix4(const Matrix4& rhs);
	Matrix4(const double newData[ELEMENT_COUNT]);
	~Matrix4();

	// Operator Overloads
	Matrix4& operator=(const Matrix4& rhs);
	double* operator[](const size_t& rIndex);
	Matrix4 operator+(const Matrix4& rhs) const;
	Matrix4 operator-(const Matrix4& rhs) const;
	Matrix4 operator*(const Matrix4& rhs) const;
	Matrix4 operator*(const double& rhs) const;
	Matrix4 operator<<(const Matrix4& rhs) const;
	Matrix4 operator>>(const Matrix4& rhs) const;
	Matrix4& operator+=(const Matrix4& rhs);
	Matrix4& operator-=(const Matrix4& rhs);
	Matrix4& operator*=(const Matrix4& rhs);
	Matrix4& operator*=(const double& rhs);
	Matrix4& operator<<=(const Matrix4& rhs);
	Matrix4& operator>>=(const Matrix4& rhs);
	Matrix4 operator-() const;
	Matrix4 operator~() const;
	bool operator==(const Matrix4& rhs) const;
	bool operator!=(const Matrix4& rhs) const;
	friend std::ostream& operator<<(std::ostream& os, const Matrix4& rhs);

	// Miscellaneous
	void transpose();
	void negate();

	// Friend Functions
	friend Matrix4 M_transpose(const Matrix4& rhs);
	friend Matrix4 M_negative(const Matrix4& rhs);

	// Transformations
		// Scale
	void scale(const double& s);
	void scale(const double& x, const double& y, const double& z);
	void scaleX(const double& s);
	void scaleY(const double& s);
	void scaleZ(const double& s);
		// Translate
	void translate(const double& x, const double& y, const double& z);
	void translateX(const double& t);
	void translateY(const double& t);
	void translateZ(const double& t);
		// Rotate
	void rotate(
		const double& r,
		const double& x,
		const double& y,
		const double& z
	);
	void rotateX(const double& r);
	void rotateY(const double& r);
	void rotateZ(const double& r);

	// Static Transform Matrices
		// Scale
	static Matrix4 M_scale(const double& s);
	static Matrix4 M_scale(
		const double& x,
		const double& y,
		const double& z
	);
		// Translate
	static Matrix4 M_translate(
		const double& x,
		const double& y,
		const double& z
	);
		// Rotate
	static Matrix4 M_rotate(
		const double& r,
		const double& x,
		const double& y,
		const double& z
	);
	static Matrix4 M_rotateX(const double& r);
	static Matrix4 M_rotateY(const double& r);
	static Matrix4 M_rotateZ(const double& r);

private:

	// data in the matrix
	double data[ELEMENT_COUNT];

};

struct Vector4 {

	Vector4();
	Vector4(const Vector& rhs);
	Vector4(const double[DIMENSION]);
	~Vector4();

private:

	// data in the vector
	double data[DIMENSION];
};

#endif

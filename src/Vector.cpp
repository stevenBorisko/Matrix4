#include <Matrix4.hpp>

// CONSTRUCTORS

Vector4::Vector4() {
	memset(this->data, 0, VECTOR_DATA_SIZE);
}

Vector4::Vector4(const Vector4& rhs) {
	if(this == &rhs) return;
	memcpy(this->data, rhs.data, VECTOR_DATA_SIZE);
}

Vector4::Vector4(
	const double& x,
	const double& y,
	const double& z,
	const double& w
) {
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
	this->data[3] = w;
}

Vector4::Vector4(const double newData[DIMENSION]) {
	memcpy(this->data, newData, VECTOR_DATA_SIZE);
}

Vector4::~Vector4() { }

// OPERATOR OVERLOADS

	// Assignment
Vector4& Vector4::operator=(const Vector4& rhs) {
	memcpy(this->data, rhs.data, VECTOR_DATA_SIZE);
	return *this;
}

double Vector4::operator[](const size_t& index) const {
	return this->data[index];
}

double& Vector4::operator[](const size_t& index) {
	return this->data[index];
}

	// Binary
Vector4 Vector4::operator+(const Vector4& rhs) const {
	Vector4 ret(*this);
	ret += rhs;
	return ret;
}

Vector4 Vector4::operator-(const Vector4& rhs) const {
	Vector4 ret(*this);
	ret -= rhs;
	return ret;
}

Vector4 Vector4::operator*(const double& rhs) const {
	Vector4 ret(*this);
	ret *= rhs;
	return ret;
}

	// Binary Assignment
Vector4& Vector4::operator+=(const Vector4& rhs) {
	this->data[0] += rhs.data[0];
	this->data[1] += rhs.data[1];
	this->data[2] += rhs.data[2];
	this->data[3] += rhs.data[3];
	return *this;
}

Vector4& Vector4::operator-=(const Vector4& rhs) {
	this->data[0] -= rhs.data[0];
	this->data[1] -= rhs.data[1];
	this->data[2] -= rhs.data[2];
	this->data[3] -= rhs.data[3];
	return *this;
}

Vector4& Vector4::operator*=(const double& rhs) {
	this->data[0] *= rhs;
	this->data[1] *= rhs;
	this->data[2] *= rhs;
	this->data[3] *= rhs;
	return *this;
}

Vector4& Vector4::operator>>=(const Matrix4& rhs) {
	double temp[4];
	temp[0] = this->data[0] * rhs[0][0]
		+ this->data[1] * rhs[0][1]
		+ this->data[2] * rhs[0][2]
		+ this->data[3] * rhs[0][3];
	temp[1] = this->data[0] * rhs[1][0]
		+ this->data[1] * rhs[1][1]
		+ this->data[2] * rhs[1][2]
		+ this->data[3] * rhs[1][3];
	temp[2] = this->data[0] * rhs[2][0]
		+ this->data[1] * rhs[2][1]
		+ this->data[2] * rhs[2][2]
		+ this->data[3] * rhs[2][3];
	temp[3] = this->data[0] * rhs[3][0]
		+ this->data[1] * rhs[3][1]
		+ this->data[2] * rhs[3][2]
		+ this->data[3] * rhs[3][3];
	memcpy(this->data, temp, VECTOR_DATA_SIZE);
	return *this;
}

	// Unary
Vector4 Vector4::operator-() const {
	Vector4 ret;
	ret.data[0] = -this->data[0];
	ret.data[1] = -this->data[1];
	ret.data[2] = -this->data[2];
	ret.data[3] = -this->data[3];
	return ret;
}

	// Relational
bool Vector4::operator==(const Vector4& rhs) const {
	bool equal = true;
	equal &= (this->data[0] == rhs.data[0]);
	equal &= (this->data[1] == rhs.data[1]);
	equal &= (this->data[2] == rhs.data[2]);
	equal &= (this->data[3] == rhs.data[3]);
	return equal;
}

bool Vector4::operator!=(const Vector4& rhs) const {
	return !(*this == rhs);
}

	// ostream
std::ostream& operator<<(std::ostream& os, const Vector4& rhs) {
	return os << "[ " << rhs.data[0]
		<< " " << rhs.data[1]
		<< " " << rhs.data[2]
		<< " " << rhs.data[3]
		<< " ]";
}

// Miscellaneous

void Vector4::normalize() {
	this->scale(1.0 / V_magnitude(*this));
}

// Friend

double V_magnitude(const Vector4& vec) {
	return sqrt(V_dot(vec,vec));
}

Vector4 V_normalize(const Vector4& vec) {
	Vector4 ret(vec);
	ret.normalize();
	return ret;
}

double V_distance(const Vector4& vec0, const Vector4& vec1) {
	return V_magnitude(vec1 - vec0);
}

double V_dot(const Vector4& vec0, const Vector4& vec1) {
	return (vec0.data[0] * vec1.data[0]
		+ vec0.data[1] * vec1.data[1]
		+ vec0.data[2] * vec1.data[2]);
}

Vector4 V_cross(const Vector4& vec0, const Vector4& vec1) {
	Vector4 ret;
	ret.data[0] = vec0.data[1] * vec1.data[2] - vec0.data[2] * vec1.data[1];
	ret.data[1] = vec0.data[2] * vec1.data[0] - vec0.data[0] * vec1.data[2];
	ret.data[2] = vec0.data[0] * vec1.data[1] - vec0.data[1] * vec1.data[0];
	return ret;
}

// Transformations
	// Scale
void Vector4::scale(const double& s) {
	this->data[0] *= s;
	this->data[1] *= s;
	this->data[2] *= s;
}

void Vector4::scale(const double& x, const double& y, const double& z) {
	this->data[0] *= x;
	this->data[1] *= y;
	this->data[2] *= z;
}

void Vector4::scaleX(const double& s) {
	this->data[0] *= s;
}

void Vector4::scaleY(const double& s) {
	this->data[1] *= s;
}

void Vector4::scaleZ(const double& s) {
	this->data[2] *= s;
}

	// Translate
void Vector4::translate(const double& x, const double& y, const double& z) {
	this->data[0] += x;
	this->data[1] += y;
	this->data[2] += z;
}

void Vector4::translateX(const double& t) {
	this->data[0] += t;
}

void Vector4::translateY(const double& t) {
	this->data[1] += t;
}

void Vector4::translateZ(const double& t) {
	this->data[2] += t;
}

	// Rotate
void Vector4::rotate(
	const double& r,
	const double& x,
	const double& y,
	const double& z
) {
	*this >>= Matrix4::M_rotate(r,x,y,z);
}

void Vector4::rotateX(const double& r) {
	*this >>= Matrix4::M_rotateX(r);
}

void Vector4::rotateY(const double& r) {
	*this >>= Matrix4::M_rotateY(r);
}

void Vector4::rotateZ(const double& r) {
	*this >>= Matrix4::M_rotateZ(r);
}

#include <Matrix4.hpp>

Matrix4 Matrix4::M_scale(const double& s) {
	Matrix4 ret;
	ret.data[0] = s;
	ret.data[5] = s;
	ret.data[10] = s;
	return ret;
}

Matrix4 Matrix4::M_scale(const double& x, const double& y, const double& z) {
	Matrix4 ret;
	ret.data[0] = x;
	ret.data[5] = y;
	ret.data[10] = z;
	return ret;
}

Matrix4 Matrix4::M_translate(const double& x, const double& y, const double& z) {
	Matrix4 ret;
	ret.data[3] = x;
	ret.data[7] = y;
	ret.data[11] = z;
	return ret;
}

Matrix4 Matrix4::M_rotate(
	const double& r,
	const double& x,
	const double& y,
	const double& z
) {
	Matrix4 ret;

	double s = sin(r);
	double c = cos(r);
	double omc = 1.0 - c;
	double xDir = x;
	double yDir = y;
	double zDir = z;

	double m = sqrt(x*x + y*y + z*z);
	if(m != 1.0) {
		double minv = 1.0 / m;
		xDir *= minv;
		yDir *= minv;
		zDir *= minv;
	}

	ret.data[0] = xDir * xDir * omc + c;
	ret.data[1] = xDir * yDir * omc - zDir * s;
	ret.data[2] = xDir * zDir * omc + yDir * s;

	ret.data[4] = yDir * xDir * omc + zDir * s;
	ret.data[5] = yDir * yDir * omc + c;
	ret.data[6] = yDir * zDir * omc - xDir * s;

	ret.data[8] = zDir * xDir * omc - yDir * s;
	ret.data[9] = zDir * yDir * omc + xDir * s;
	ret.data[10]= zDir * zDir * omc + c;

	return ret;
}

Matrix4 Matrix4::M_rotateX(const double& r) {
	Matrix4 ret;

	double s = sin(r);
	double c = cos(r);

	ret.data[5] = c;
	ret.data[6] = -s;
	ret.data[9] = s;
	ret.data[10] = c;

	return ret;
}

Matrix4 Matrix4::M_rotateY(const double& r) {
	Matrix4 ret;

	double s = sin(r);
	double c = cos(r);

	ret.data[0] = c;
	ret.data[2] = s;
	ret.data[8] = -s;
	ret.data[10] = c;

	return ret;
}

Matrix4 Matrix4::M_rotateZ(const double& r) {
	Matrix4 ret;

	double s = sin(r);
	double c = cos(r);

	ret.data[0] = c;
	ret.data[1] = -s;
	ret.data[4] = s;
	ret.data[5] = c;

	return ret;
}

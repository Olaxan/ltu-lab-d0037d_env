#include "matharr.h"

#include <sstream>

namespace efiilj
{

	Matrix2D::Matrix2D()
	{
		this->a(0);
		this->b(0);
		this->c(0);
		this->d(0);
	}

	Matrix2D::Matrix2D(const Matrix2D &copy)
	{
		this->a(copy.a());
		this->b(copy.b());
		this->c(copy.c());
		this->d(copy.d());
	}

	Matrix2D::Matrix2D(float a, float b, float c, float d) {
		this->a(a);
		this->b(b);
		this->c(c);
		this->d(d);
	}

	Matrix2D Matrix2D::operator*(const Matrix2D &other) const
	{
		Matrix2D mat;
		mat.a(this->a() * other.a() + this->b() * other.c());
		mat.b(this->a() * other.b() + this->b() * other.d());
		mat.c(this->c() * other.a() + this->d() * other.c());
		mat.d(this->c() * other.b() + this->d() * other.d());

		return mat;
	}

	Matrix2D& Matrix2D::operator=(const Matrix2D &other)
	{
		this->a(other.a());
		this->b(other.b());
		this->c(other.c());
		this->d(other.d());

		return *this;
	}

	Matrix2D* Matrix2D::getRotated(const float &angle) const
	{
		return new Matrix2D((*this) * Matrix2D(cos(angle), -sin(angle), sin(angle), cos(angle)));
	}

	Matrix2D* Matrix2D::getTransposed() const
	{
		return new Matrix2D(this->a(), this->c(), this->b(), this->d());
	}

	std::string Matrix2D::to_string()
	{
		std::stringstream ss;
		ss << a() << ", " << b() << ";\n" << c() << ", " << d() << ";\n";
		return ss.str();
	}

	Matrix2D::~Matrix2D()
	{
	}

}


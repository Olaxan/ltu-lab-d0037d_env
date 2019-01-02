#include "matharr.h"

#include <sstream>

namespace Assignment
{

	Matrix2::Matrix2(const Matrix2 &copy)
	{
		*this = copy;
	}

	Matrix2::Matrix2(float a, float b, float c, float d) {
		this->a(a);
		this->b(b);
		this->c(c);
		this->d(d);
	}

	Matrix2 Matrix2::operator*(const Matrix2 &other) const
	{
		Matrix2 mat;
		mat.a(this->a() * other.a() + this->b() * other.c());
		mat.b(this->a() * other.b() + this->b() * other.d());
		mat.c(this->c() * other.a() + this->d() * other.c());
		mat.d(this->c() * other.b() + this->d() * other.d());

		return mat;
	}

	Matrix2& Matrix2::operator=(const Matrix2 &other)
	{
		this->a(other.a());
		this->b(other.b());
		this->c(other.c());
		this->d(other.d());

		return *this;
	}

	Matrix2 Matrix2::getRotationMatrix(const float & deg)
	{
		return Matrix2(cos(deg), -sin(deg), sin(deg), cos(deg));
	}

	Matrix2 Matrix2::getTransposed() const
	{
		return Matrix2(this->a(), this->c(), this->b(), this->d());
	}

	std::string Matrix2::to_string()
	{
		std::stringstream ss;
		ss << a() << ", " << b() << ";\n" << c() << ", " << d() << ";\n";
		return ss.str();
	}

	Matrix2::~Matrix2()
	{
	}

}


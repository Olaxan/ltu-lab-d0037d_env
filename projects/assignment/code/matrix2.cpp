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

	Matrix2 Matrix2::operator * (const Matrix2 &other) const
	{
		Matrix2 mat;

		mat(0, 0) = Vector3::dot(row(0), other.col(0));;
		mat(0, 1) = Vector3::dot(row(1), other.col(0));;

		mat(1, 0) = Vector3::dot(row(0), other.col(1));;
		mat(1, 1) = Vector3::dot(row(1), other.col(1));;

		return mat;
	}

	Matrix2& Matrix2::operator = (const Matrix2 &other)
	{
		this->a(other.a());
		this->b(other.b());
		this->c(other.c());
		this->d(other.d());

		return *this;
	}

	Vector2 & Matrix2::operator *= (Vector2 & other) const
	{
		other = (*this) * other;
		return other;
	}

	Vector2 Matrix2::operator * (const Vector2 & other) const
	{
		Vector2 vect;
		vect.x(other.dot(row(0)));
		vect.y(other.dot(row(1)));
		return vect;
	}

	float & Matrix2::operator()(int x, int y)
	{
		return _arr[y][x];
	}

	float Matrix2::at(int x, int y) const
	{
		return _arr[y].at(x);
	}

	void Matrix2::clear(bool identity)
	{
		for (int i = 0; i < 4; i++)
		{
			_arr[i] = identity && (i % 3 == 0);
		}
	}

	Vector2 Matrix2::row(int y) const
	{
		return Vector2(at(0, y), at(1, y));
	}

	Vector2 Matrix2::col(int x) const
	{
		return Vector2(at(x, 0), at(x, 1));
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


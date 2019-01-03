#include "matharr.h"

#include <sstream>

namespace Assignment
{
	Matrix3::Matrix3()
	{
		clear();
	}

	Matrix3::Matrix3(const Matrix2 & copy)
	{
		clear();

		(*this)(0, 0) = copy.a();
		(*this)(1, 0) = copy.b();
		(*this)(0, 1) = copy.c();
		(*this)(1, 1) = copy.d();
	}

	Matrix3::Matrix3(const Matrix3 &copy)
	{
		*this = copy;
	}

	Matrix3::Matrix3(Vector3 & x, Vector3 & y, Vector3 & z)
	{
		_arr[0] = x;
		_arr[1] = y;
		_arr[2] = z;
	}

	Matrix3 Matrix3::operator * (const Matrix3 &other) const
	{
		Matrix3 mat;

		mat(0, 0) = Vector3::dot(row(0), other.col(0));
		mat(0, 1) = Vector3::dot(row(1), other.col(0));
		mat(0, 2) = Vector3::dot(row(2), other.col(0));

		mat(1, 0) = Vector3::dot(row(0), other.col(1));
		mat(1, 1) = Vector3::dot(row(1), other.col(1));
		mat(1, 2) = Vector3::dot(row(2), other.col(1));

		mat(2, 0) = Vector3::dot(row(0), other.col(2));
		mat(2, 1) = Vector3::dot(row(1), other.col(2));
		mat(2, 2) = Vector3::dot(row(2), other.col(2));

		return mat;
	}

	Matrix3& Matrix3::operator = (const Matrix3 &other)
	{
		(*this)(0, 0) = other.at(0, 0);
		(*this)(0, 1) = other.at(0, 1);
		(*this)(0, 2) = other.at(0, 2);

		(*this)(1, 0) = other.at(1, 0);
		(*this)(1, 1) = other.at(1, 1);
		(*this)(1, 2) = other.at(1, 2);

		(*this)(2, 0) = other.at(2, 0);
		(*this)(2, 1) = other.at(2, 1);
		(*this)(2, 2) = other.at(2, 2);

		return *this;
	}

	Vector3 & Matrix3::operator *= (Vector3 & other) const
	{
		other = (*this) * other;
		return other;
	}

	Vector3 Matrix3::operator * (const Vector3 & other) const
	{
		Vector3 vect;
		vect.x(other.dot(row(0)));
		vect.y(other.dot(row(1)));
		vect.z(other.dot(row(2)));
		return vect;
	}

	float & Matrix3::operator()(int i)
	{
		return _arr[i / 3][i % 3];
	}

	float & Matrix3::operator()(int x, int y)
	{
		return _arr[y][x];
	}

	float Matrix3::at(int n) const
	{
		return at(n / 3, n % 3);
	}

	float Matrix3::at(int x, int y) const
	{
		return _arr[y].at(x);
	}

	Vector3 Matrix3::row(int y) const
	{
		return Vector3(at(0, y), at(1, y), at(2, y));
	}

	Vector3 Matrix3::col(int x) const
	{
		return Vector3(at(x, 0), at(x, 1), at(x, 2));
	}

	void Matrix3::clear(bool identity)
	{
		for (int i = 0; i < 9; i++)
		{
			(*this)(i) = identity && (i % 4 == 0);
		}
	}

	Matrix3 Matrix3::getTransposed() const
	{
		Matrix3 mat;

		mat(0, 0) = at(0, 0);
		mat(0, 1) = at(1, 0);
		mat(0, 2) = at(2, 0);

		mat(1, 0) = at(0, 1);
		mat(1, 1) = at(1, 1);
		mat(1, 2) = at(2, 1);

		mat(2, 0) = at(0, 2);
		mat(2, 1) = at(1, 2);
		mat(2, 2) = at(2, 2);

		return mat;
	}

	Matrix3 Matrix3::getTranslation(const Vector3 & v)
	{
		Matrix3 mat = Matrix3();
		mat(2, 0) = v.x();
		mat(2, 1) = v.y();
		mat(2, 2) = v.z();
		return mat;
	}

	Matrix3 Matrix3::getRotationMatrix(const float & rad)
	{
		Matrix2 mat = Matrix2::getRotationMatrix(rad);
		return Matrix3(mat);
	}

	std::string Matrix3::to_string()
	{
		std::stringstream ss;
		ss << at(0, 0) << ", " << at(1, 0) << ", " << at(2, 0) << ";\n";
		ss << at(0, 1) << ", " << at(1, 1) << ", " << at(2, 1) << ";\n";
		ss << at(0, 2) << ", " << at(1, 2) << ", " << at(2, 2) << ";\n";
		return ss.str();
	}

	Matrix3::~Matrix3() { }

}


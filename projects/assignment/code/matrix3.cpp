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
		clear(false);

		(*this)(0, 0) = copy.a();
		(*this)(1, 0) = copy.b();
		(*this)(0, 1) = copy.c();
		(*this)(1, 1) = copy.d();
	}

	Matrix3::Matrix3(const Matrix3 &copy)
	{
		*this = copy;
	}

	Matrix3 Matrix3::operator * (const Matrix3 &other) const
	{
		Matrix3 mat;
		mat(0, 0) = this->at(0, 0) * other.at(0, 0) + this->at(1, 0) * other.at(0, 1) + this->at(2, 0) * other.at(0, 2);
		mat(0, 1) = this->at(0, 1) * other.at(0, 0) + this->at(1, 1) * other.at(0, 1) + this->at(2, 1) * other.at(0, 2);
		mat(0, 2) = this->at(0, 2) * other.at(0, 0) + this->at(1, 2) * other.at(0, 1) + this->at(2, 2) * other.at(0, 2);

		mat(1, 0) = this->at(0, 0) * other.at(1, 0) + this->at(1, 0) * other.at(1, 1) + this->at(2, 0) * other.at(1, 2);
		mat(1, 1) = this->at(0, 1) * other.at(1, 0) + this->at(1, 1) * other.at(1, 1) + this->at(2, 1) * other.at(1, 2);
		mat(1, 2) = this->at(0, 2) * other.at(1, 0) + this->at(1, 2) * other.at(1, 1) + this->at(2, 2) * other.at(1, 2);

		mat(2, 0) = this->at(0, 1) * other.at(2, 0) + this->at(1, 0) * other.at(2, 1) + this->at(2, 0) * other.at(2, 2);
		mat(2, 1) = this->at(0, 1) * other.at(2, 0) + this->at(1, 1) * other.at(2, 1) + this->at(2, 1) * other.at(2, 2);
		mat(2, 2) = this->at(0, 2) * other.at(2, 0) + this->at(1, 2) * other.at(2, 1) + this->at(2, 2) * other.at(2, 2);
	
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

	float & Matrix3::operator()(int x, int y)
	{
		return _arr[x * 3 + y];
	}

	float Matrix3::at(int x, int y) const
	{
		return _arr[x * 3 + y];
	}

	void Matrix3::clear(bool identity)
	{
		for (int i = 0; i < 9; i++)
		{
			_arr[i] = identity ^ (i % 4 == 0);
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

	std::string Matrix3::to_string()
	{
		std::stringstream ss;
		ss << at(0, 0) << ", " << at(1, 0) << ", " << at(2, 0) << ";\n";
		ss << at(0, 1) << ", " << at(1, 1) << ", " << at(2, 1) << ";\n";
		ss << at(0, 2) << ", " << at(1, 2) << ", " << at(2, 2) << ";\n";
		return ss.str();
	}

	Matrix3::~Matrix3()
	{
	}

}


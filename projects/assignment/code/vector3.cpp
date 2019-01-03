#include "matharr.h"

#include <cmath>

#ifdef _DEBUG
#include <iostream>
#endif

//Hash
namespace std
{
	template <>
	struct hash<Assignment::Vector3>
	{
		size_t operator()(const Assignment::Vector3& v) const
		{
			// http://stackoverflow.com/a/1646913/126995
			size_t res = 17;
			res = res * 31 + hash<float>()(v.x());
			res = res * 31 + hash<float>()(v.y());
			res = res * 31 + hash<float>()(v.z());
			return res;
		}
	};
}

namespace Assignment
{

	Vector3::Vector3(const Vector2 &copy)
	{
		this->x(copy.x());
		this->y(copy.y());
		this->z(0);
	}

	Vector3::Vector3(const Vector3 &copy)
	{
		*this = copy;
	}

	Vector3::Vector3(float x, float y, float z)
	{
		this->x(x);
		this->y(y);
		this->z(z);
	}

	Vector3 Vector3::operator + (const Vector3& other) const
	{
		Vector3 vect;
		vect.x(this->x() + other.x());
		vect.y(this->y() + other.y());
		vect.z(this->z() + other.z());
		return vect;
	}

	Vector3 Vector3::operator - (const Vector3& other) const
	{
		Vector3 vect;
		vect.x(this->x() - other.x());
		vect.y(this->y() - other.y());
		vect.z(this->z() - other.z());
		return vect;
	}

	Vector3 Vector3::operator * (const Vector3& other) const
	{
		Vector3 vect;
		vect.x(this->x() * other.x());
		vect.y(this->y() * other.y());
		vect.z(this->z() * other.z());
		return vect;
	}

	Vector3& Vector3::operator *= (const Matrix3 & other)
	{
		(*this) = other * (*this);
		return *this;
	}

	Vector3& Vector3::operator += (const Vector3 & other)
	{
		(*this) = (*this) + other;
		return *this;
	}

	Vector3& Vector3::operator -= (const Vector3 & other)
	{
		(*this) = (*this) - other;
		return *this;
	}

	float & Vector3::operator [] (const int & index)
	{
		if (index > 2)
			throw new std::out_of_range("Vector index out of range");

		return _arr[index];
	}

	float Vector3::at(int y) const
	{
		if (y > 2)
			throw new std::out_of_range("Vector index out of range");

		return _arr[y];
	}

	bool Vector3::operator == (const Vector3& other) const
	{
		return (std::hash<Vector3>()(*this) == std::hash<Vector3>()(other));
	}

	bool Vector3::operator != (const Vector3& other) const
	{
		return (std::hash<Vector3>()(*this) != std::hash<Vector3>()(other));
	}

	float Vector3::dot(const Vector3 & x, const Vector3 & y)
	{
		return x.dot(y);
	}

	float Vector3::dot(const Vector3& other) const
	{
		return (this->x() * other.x() + this->y() * other.y() + this->z() * other.z());
	}

	float Vector3::norm() const
	{
		return sqrt(powf(this->x(), 2) + powf(this->y(), 2) + powf(this->z(), 2));
	}

	Vector3 Vector3::getTransformed(const Matrix3 &trans) const
	{
		return Vector3(trans * (*this));
	}

	std::string Vector3::to_string() const
	{
		return std::to_string(this->x()) + ";\n" + std::to_string(this->y()) + ";\n" + std::to_string(this->z()) + ";\n";
	}

	Vector3::~Vector3() { }

}


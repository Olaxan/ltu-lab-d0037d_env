#include "matharr.h"

#include <cmath>

namespace Assignment
{

	Vector3::Vector3(const Vector3& copy)
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
		vect.y(this->z() * other.z());
		return vect;
	}

	Vector3 Vector3::operator * (const Matrix3& other) const
	{
		Vector3 vect;
		vect.x(other.a() * this->x() + other.b() * this->y());
		vect.y(other.c() * this->x() + other.d() * this->y());
		return vect;
	}

	Vector3& Vector3::operator+=(const Vector3 & other)
	{
		(*this) = (*this) + other;
		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3 & other)
	{
		(*this) = (*this) - other;
		return *this;
	}

	Vector3 & Vector3::operator*=(const Matrix3 & other)
	{
		(*this) = (*this) * other;
		return (*this);
	}

	bool Vector3::operator == (const Vector3& other) const
	{
		return (this->y() == other.y() && this->x() == other.x());
	}

	bool Vector3::operator != (const Vector3& other) const
	{
		return (this->y() != other.y() || this->x() != other.x());
	}

	float Vector3::dot(const Vector3& other) const
	{
		return (this->x() * other.x() + this->y() * other.y());
	}

	float Vector3::norm() const
	{
		return sqrt(powf(this->x(), 2) + powf(this->y(), 2));
	}

	Vector3 Vector3::getTransformed(const Matrix2 &trans) const
	{
		return Vector3((*this) * trans);
	}

	std::string Vector3::to_string() const
	{
		return std::to_string(this->x()) + ";\n" + std::to_string(this->y()) + ";\n";
	}

	Vector3::~Vector3() { }

}


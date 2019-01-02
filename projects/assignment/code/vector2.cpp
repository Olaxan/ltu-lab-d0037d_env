#include "matharr.h"

#include <cmath>

namespace Assignment
{

	Vector2::Vector2(const Vector2& copy)
	{
		this->x(copy.x());
		this->y(copy.y());
	}

	Vector2::Vector2(float x, float y)
	{
		this->x(x);
		this->y(y);
	}

	Vector2& Vector2::operator+=(const Vector2 & other)
	{
		this->x(this->x() + other.x());
		this->y(this->y() + other.y());
		return *this;
	}

	Vector2& Vector2::operator-=(const Vector2 & other)
	{
		this->x(this->x() - other.x());
		this->y(this->y() - other.y());
		return *this;
	}

	Vector2 & Vector2::operator*=(const Matrix2 & other)
	{
		(*this) = (*this) * other;
		return (*this);
	}

	Vector2 Vector2::operator + (const Vector2& other) const
	{
		Vector2 vect;
		vect.x(this->x() + other.x());
		vect.y(this->y() + other.y());
		return vect;
	}

	Vector2 Vector2::operator - (const Vector2& other) const
	{
		Vector2 vect;
		vect.x(this->x() - other.x());
		vect.y(this->y() - other.y());
		return vect;
	}

	Vector2 Vector2::operator * (const Vector2& other) const
	{
		Vector2 vect;
		vect.x(this->x() * other.x());
		vect.y(this->y() * other.y());
		return vect;
	}

	Vector2 Vector2::operator * (const Matrix2& other) const
	{
		Vector2 vect;
		vect.x(other.a() * this->x() + other.b() * this->y());
		vect.y(other.c() * this->x() + other.d() * this->y());
		return vect;
	}

	bool Vector2::operator == (const Vector2& other) const
	{
		return (this->y() == other.y() && this->x() == other.x());
	}

	bool Vector2::operator != (const Vector2& other) const
	{
		return (this->y() != other.y() || this->x() != other.x());
	}

	float Vector2::dot(const Vector2& other) const
	{
		return (this->x() * other.x() + this->y() * other.y());
	}

	float Vector2::norm() const
	{
		return sqrt(powf(this->x(), 2) + powf(this->y(), 2));
	}

	Vector2 Vector2::getTransformed(const Matrix2 &trans) const
	{
		return Vector2((*this) * trans);
	}

	std::string Vector2::to_string() const
	{
		return std::to_string(this->x()) + ";\n" + std::to_string(this->y()) + ";\n";
	}

	Vector2::~Vector2() { }

}


#include "matharr.h"

#include <cmath>

namespace efiilj
{

	Vector2D::Vector2D()
	{
		this->x(0);
		this->y(0);
	}

	Vector2D::Vector2D(const Vector2D& copy)
	{
		this->x(copy.x());
		this->y(copy.y());
	}

	Vector2D::Vector2D(float x, float y)
	{
		this->x(x);
		this->y(y);
	}

	Vector2D Vector2D::operator + (const Vector2D& other) const
	{
		Vector2D vect;
		vect.x(this->x() + other.x());
		vect.y(this->y() + other.y());
		return vect;
	}

	Vector2D Vector2D::operator - (const Vector2D& other) const
	{
		Vector2D vect;
		vect.x(this->x() - other.x());
		vect.y(this->y() - other.y());
		return vect;
	}

	Vector2D Vector2D::operator * (const Vector2D& other) const
	{
		Vector2D vect;
		vect.x(this->x() * other.x());
		vect.y(this->y() * other.y());
		return vect;
	}

	Vector2D Vector2D::operator * (const Matrix2D& other) const
	{
		Vector2D vect;
		vect.x(other.a() * this->x() + other.b() * this->y());
		vect.y(other.c() * this->x() + other.d() * this->y());
		return vect;
	}

	bool Vector2D::operator == (const Vector2D& other) const
	{
		return (this->y() == other.y() && this->x() == other.x());
	}

	bool Vector2D::operator != (const Vector2D& other) const
	{
		return (this->y() != other.y() || this->x() != other.x());
	}

	float Vector2D::dot(const Vector2D& other) const
	{
		return (this->x() * other.x() + this->y() * other.y());
	}

	float Vector2D::norm() const
	{
		return sqrt(powf(this->x(), 2) + powf(this->y(), 2));
	}

	Vector2D* Vector2D::getTransformed(const Matrix2D &trans) const
	{
		return new Vector2D((*this) * trans);
	}

	std::string Vector2D::to_string() const
	{
		return std::to_string(this->x()) + ", " + std::to_string(this->y());
	}

	Vector2D::~Vector2D() { }

}


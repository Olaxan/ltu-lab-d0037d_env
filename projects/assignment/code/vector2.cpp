#include "matharr.h"

#include <cmath>
#include <stdexcept>

//Hash
namespace std
{
	template <>
	struct hash<Assignment::Vector2>
	{
		size_t operator()(const Assignment::Vector2& v) const
		{
			// http://stackoverflow.com/a/1646913/126995
			size_t res = 17;
			res = res * 31 + hash<float>()(v.x());
			res = res * 31 + hash<float>()(v.y());
			return res;
		}
	};
}

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

	Vector2& Vector2::operator += (const Vector2 & other)
	{
		this->x(this->x() + other.x());
		this->y(this->y() + other.y());
		return *this;
	}

	Vector2& Vector2::operator -= (const Vector2 & other)
	{
		this->x(this->x() - other.x());
		this->y(this->y() - other.y());
		return *this;
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

	Vector2 & Vector2::operator*=(const Matrix2 & other)
	{
		other *= (*this);
		return *this;
	}

	float & Vector2::operator[](const int &index)
	{
		if (index > 2)
			throw new std::out_of_range("Vector index out of range");

		return _arr[index];
	}

	float Vector2::at(int y) const
	{
		if (y > 1)
			throw new std::out_of_range("Vector index out of range");

		return _arr[y];
	}

	bool Vector2::operator == (const Vector2& other) const
	{
		return (std::hash<Vector2>()(*this) == std::hash<Vector2>()(other));
	}

	bool Vector2::operator != (const Vector2& other) const
	{
		return (std::hash<Vector2>()(*this) != std::hash<Vector2>()(other));
	}

	float Vector2::dot(const Vector2 & x, const Vector2 & y)
	{
		return x.dot(y);
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
		return Vector2(trans * (*this));
	}

	std::string Vector2::to_string() const
	{
		return std::to_string(this->x()) + ";\n" + std::to_string(this->y()) + ";\n";
	}

	Vector2::~Vector2() { }

}


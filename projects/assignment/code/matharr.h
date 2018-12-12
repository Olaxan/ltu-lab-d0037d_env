#pragma once

#include <string>

namespace Assignment
{

	class Matrix2D
	{
	private:
		float _arr[4];
	public:
		Matrix2D();
		Matrix2D(const Matrix2D &copy);
		Matrix2D(float a, float b, float c, float d);

		Matrix2D operator * (const Matrix2D &other) const;
		Matrix2D& operator = (const Matrix2D &other);

		const float& a() const { return this->_arr[0]; }
		void a(const float& a) { this->_arr[0] = a; }

		const float& b() const { return this->_arr[1]; }
		void b(const float& b) { this->_arr[1] = b; }

		const float& c() const { return this->_arr[2]; }
		void c(const float& c) { this->_arr[2] = c; }

		const float& d() const { return this->_arr[3]; }
		void d(const float& d) { this->_arr[3] = d; }

		//Applies a rotation the the matrix (in degrees). Returns a pointer to the new resulting Matrix2D.
		Matrix2D* getRotated(const float &angle) const;

		//Switch rows/columns in the matrix. Returns a pointer to the new resulting Matrix2D. 
		Matrix2D* getTransposed() const;

		std::string to_string();

		~Matrix2D();
	};

	class Vector2D
	{
	private:
		float _arr[2];
	public:
		Vector2D();
		Vector2D(const Vector2D &copy);
		Vector2D(float x, float y);

		Vector2D operator + (const Vector2D &other) const;
		Vector2D operator - (const Vector2D &other) const;
		Vector2D operator * (const Vector2D &other) const;
		Vector2D operator * (const Matrix2D &other) const;

		bool operator == (const Vector2D &other) const;
		bool operator != (const Vector2D &other) const;

		const float& x() const { return this->_arr[0]; }
		void x(const float& x) { this->_arr[0] = x; }

		const float& y() const { return _arr[1]; }
		void y(const float& y) { this->_arr[1] = y; }

		float dot(const Vector2D &other) const;
		float norm() const;

		//Performs a matrix transformation on the Vector2D. Returns a pointer to the new resulting Vector2D.
		Vector2D* getTransformed(const Matrix2D &trans) const;

		std::string to_string() const;

		~Vector2D();
	};

}


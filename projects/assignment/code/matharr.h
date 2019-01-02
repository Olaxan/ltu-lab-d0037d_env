#pragma once

#include <string>

namespace Assignment
{
	class Matrix2
	{
	private:
		float _arr[4];
	public:
		Matrix2(const Matrix2 &copy);
		Matrix2(float a = 0, float b = 0, float c = 0, float d = 0);

		Matrix2 operator * (const Matrix2 &other) const;
		Matrix2& operator = (const Matrix2 &other);

		const float& a() const { return this->_arr[0]; }
		void a(const float& a) { this->_arr[0] = a; }

		const float& b() const { return this->_arr[1]; }
		void b(const float& b) { this->_arr[1] = b; }

		const float& c() const { return this->_arr[2]; }
		void c(const float& c) { this->_arr[2] = c; }

		const float& d() const { return this->_arr[3]; }
		void d(const float& d) { this->_arr[3] = d; }

		static Matrix2 getRotationMatrix(const float &rad);

		/// Switch rows/columns in the matrix. Returns a pointer to the new resulting Matrix2D. 
		Matrix2 getTransposed() const;

		std::string to_string();

		~Matrix2();
	};

	class Matrix3
	{
	private:
		float _arr[9];

	public:
		Matrix3();
		Matrix3(const Matrix2 &copy);
		Matrix3(const Matrix3 &copy);

		Matrix3 operator * (const Matrix3 &other) const;
		Matrix3& operator = (const Matrix3 &other);
		float& operator () (int x, int y);

		float at(int x, int y) const;

		void clear(bool identity = true);

		/// Switch rows/columns in the matrix
		Matrix3 getTransposed() const;

		std::string to_string();

		~Matrix3();
	};

	class Vector2
	{
	private:
		float _arr[2];
	public:
		Vector2(const Vector2 &copy);
		Vector2(float x = 0, float y = 0);

		Vector2& operator += (const Vector2 &other);
		Vector2& operator -= (const Vector2 &other);
		Vector2& operator *= (const Matrix2 &other);
		Vector2 operator + (const Vector2 &other) const;
		Vector2 operator - (const Vector2 &other) const;
		Vector2 operator * (const Vector2 &other) const;
		Vector2 operator * (const Matrix2 &other) const;

		bool operator == (const Vector2 &other) const;
		bool operator != (const Vector2 &other) const;

		const float& x() const { return this->_arr[0]; }
		void x(const float& x) { this->_arr[0] = x; }

		const float& y() const { return _arr[1]; }
		void y(const float& y) { this->_arr[1] = y; }

		float dot(const Vector2 &other) const;
		float norm() const;

		//Performs a matrix transformation on the Vector2D. Returns a pointer to the new resulting Vector2D.
		Vector2 getTransformed(const Matrix2 &trans) const;

		std::string to_string() const;

		~Vector2();
	};

	class Vector3
	{
	private:
		float _arr[3];

	public:
		Vector3();
		Vector3(const Vector2 &copy);
		Vector3(const Vector3 &copy);
		Vector3(float x, float y, float z);

		Vector3 operator + (const Vector3 &other) const;
		Vector3 operator - (const Vector3 &other) const;
		Vector3 operator * (const Vector3 &other) const;
		Vector3 operator * (const Matrix3 &other) const;

		Vector3& operator += (const Vector3 &other);
		Vector3& operator -= (const Vector3 &other);
		Vector3& operator *= (const Matrix3 &other);

		const float& x() const { return this->_arr[0]; }
		void x(const float& x) { this->_arr[0] = x; }

		const float& y() const { return _arr[1]; }
		void y(const float& y) { this->_arr[1] = y; }

		const float& z() const { return _arr[2]; }
		void z(const float& z) { this->_arr[2] = z; }
	};

}


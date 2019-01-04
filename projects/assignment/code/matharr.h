#pragma once

#include <string>

namespace Assignment
{
	class Matrix2;
	class Vector2
	{
	private:
		float _arr[2];
	public:
		Vector2(const Vector2 &copy);
		Vector2(float x = 0, float y = 0);

		Vector2& operator += (const Vector2 &other);
		Vector2& operator -= (const Vector2 &other);
		Vector2& operator *= (const Vector2 &other);
		Vector2& operator *= (const float &other);

		Vector2 operator + (const Vector2 &other) const;
		Vector2 operator - (const Vector2 &other) const;
		Vector2 operator * (const Vector2 &other) const;
		Vector2 operator * (const float &other) const;

		Vector2& operator *= (const Matrix2 &other);

		bool operator == (const Vector2 &other) const;
		bool operator != (const Vector2 &other) const;

		float& operator [] (const int &index);

		float at(int y) const;

		const float& x() const { return this->_arr[0]; }
		void x(const float& x) { this->_arr[0] = x; }

		const float& y() const { return _arr[1]; }
		void y(const float& y) { this->_arr[1] = y; }

		static float dist(const Vector2& x, const Vector2& y);
		static float dot(const Vector2& x, const Vector2& y);
		float dot(const Vector2 &other) const;
		float length() const;
		Vector2 norm() const;

		/// Performs a matrix transformation on the Vector2 and returns the result.
		Vector2 getTransformed(const Matrix2 &trans) const;
		Vector2 getReflection(const Vector2 &normal) const;

		std::string to_string() const;

		~Vector2();
	};

	class Matrix3;
	class Vector3
	{
	private:
		float _arr[3];

	public:
		Vector3(float x = 0, float y = 0, float z = 0);
		Vector3(bool homogenous) : Vector3(0, 0, homogenous) { }
		Vector3(const Vector2 &copy);
		Vector3(const Vector3 &copy);
		

		Vector3& operator += (const Vector3 &other);
		Vector3& operator -= (const Vector3 &other);
		Vector3& operator *= (const Vector3 &other);
		Vector3& operator *= (const float &other);

		Vector3 operator + (const Vector3 &other) const;
		Vector3 operator - (const Vector3 &other) const;
		Vector3 operator * (const Vector3 &other) const;
		Vector3 operator * (const float &other) const;

		Vector3& operator *= (const Matrix3 &other);

		bool operator == (const Vector3 &other) const;
		bool operator != (const Vector3 &other) const;

		float& operator [] (const int &index);

		float at(int y) const;

		const float& x() const { return this->_arr[0]; }
		void x(const float& x) { this->_arr[0] = x; }

		const float& y() const { return _arr[1]; }
		void y(const float& y) { this->_arr[1] = y; }

		const float& z() const { return _arr[2]; }
		void z(const float& z) { this->_arr[2] = z; }

		static float dist(const Vector3& x, const Vector3& y);
		static float dot(const Vector3& x, const Vector3& y);
		float dot(const Vector3 &other) const;
		float length() const;
		Vector3 norm() const;

		Vector3 getTransformed(const Matrix3 &trans) const;
		Vector3 getReflection(const Vector3 &normal) const;

		std::string to_string() const;

		~Vector3();
	};

	class Matrix2
	{
	private:
		Vector2 _arr[2];
	public:
		Matrix2(const Matrix2 &copy);
		Matrix2(float a = 0, float b = 0, float c = 0, float d = 0);

		Matrix2 operator * (const Matrix2 &other) const;
		Matrix2& operator = (const Matrix2 &other);

		Vector2& operator *= (Vector2 &other) const;
		Vector2 operator * (const Vector2 &other) const;

		float& operator () (int n);
		float& operator () (int x, int y);

		float at(int n) const;
		float at(int x, int y) const;

		Vector2 row(int y) const;
		Vector2 col(int x) const;

		void clear(bool identity = true);

		const float& a() const { return this->_arr[0].x(); }
		void a(const float& a) { this->_arr[0].x(a); }

		const float& b() const { return this->_arr[0].y(); }
		void b(const float& b) { this->_arr[0].y(b); }

		const float& c() const { return this->_arr[1].x(); }
		void c(const float& c) { this->_arr[1].x(c); }

		const float& d() const { return this->_arr[1].y(); }
		void d(const float& d) { this->_arr[1].y(d); }

		Matrix2 getTransposed() const;
		static Matrix2 getRotationMatrix(const float &rad);

		std::string to_string();

		~Matrix2();

		friend Vector2;
	};

	class Matrix3
	{
	private:
		Vector3 _arr[3];

	public:
		Matrix3();
		Matrix3(const Matrix2 &copy);
		Matrix3(const Matrix3 &copy);
		Matrix3(Vector3 &x, Vector3 &y, Vector3 &z);

		Matrix3 operator * (const Matrix3 &other) const;
		Matrix3& operator = (const Matrix3 &other);

		Vector3& operator *= (Vector3 &other) const;
		Vector3 operator * (const Vector3 &other) const;

		float& operator () (int i);
		float& operator () (int x, int y);

		float at(int n) const;
		float at(int x, int y) const;

		Vector3 row(int y) const;
		Vector3 col(int x) const;

		void clear(bool identity = true);

		Matrix3 getTransposed() const;
		static Matrix3 getTranslation(const Vector3 &v);
		static Matrix3 getRotationMatrix(const float &rad);

		std::string to_string();

		~Matrix3();

		friend Vector3;
	};

	

}


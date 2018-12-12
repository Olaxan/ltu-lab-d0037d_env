#pragma once

#include "matharr.h"

namespace Assignment
{
	class Shape
	{
	public:

		Vector2D position;
		Matrix2D rotation;

		unsigned int rgb;

		virtual void Update() = 0;
		virtual void Draw() = 0;

		virtual ~Shape() = 0;

	};

	class Square : public Shape
	{
	public:

		Square(float dimension = 1);

		void Update();
		void Draw();

		~Square();

	};

	class Triangle : public Shape
	{
	public:

		Triangle(float base = 1, float height = 1);

		void Update();
		void Draw();

		~Triangle();

	};

	class Circle : public Shape
	{
	public:

		Circle(float radius = 1, float segments = 8);

		void Update();
		void Draw();

		~Circle();

	};

}
#pragma once

#include "matharr.h"
#include "assignmentapp.h"

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

		float size;

		Square(float x = 0.5f, float y = 0.5f, float size = 0.5f);

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

		Circle(float radius = 1, int segments = 8);

		void Update();
		void Draw();

		~Circle();

	};

}
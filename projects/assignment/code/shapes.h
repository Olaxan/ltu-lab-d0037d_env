#pragma once

#include "matharr.h"
#include "config.h"
#include "assignmentapp.h"

namespace Assignment
{
	class Shape
	{
	protected:
		Vector2D* _vertices;
		AssignmentApp::LineData* _lines;

	public:

		Vector2D position = Vector2D(0, 0);
		Matrix2D rotation = Matrix2D::getRotationMatrix(0);

		AssignmentApp::Colour color = AssignmentApp::Colour(1, 0, 0);

		virtual void Update() = 0;
		virtual void Draw() = 0;

		virtual ~Shape() { };

	};

	class Circle : public Shape
	{
	private:
		int segments;
		float radius;
	public:

		Circle(float x = 0.5f, float y = 0.5f, float radius = 0.25f, int segments = 8);

		void Update();
		void Draw();

		~Circle();

	};

	class Square : public Shape
	{
	public:

		Square(float x = 0.5f, float y = 0.5f, float size = 0.5f);

		float size;

		void Update();
		void Draw();

		~Square();

	};

	class Triangle : public Shape
	{
	public:

		Triangle(float x = 0.5f, float y = 0.5f, float base = 1, float height = 1);

		void Update();
		void Draw();

		~Triangle();

	};

	

}
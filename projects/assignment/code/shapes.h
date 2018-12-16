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

		static const float PI_F;

		Vector2D position = Vector2D(0, 0);
		Matrix2D rotation = Matrix2D::getRotationMatrix(0);

		AssignmentApp::Colour color = AssignmentApp::Colour(1, 0, 0);

		virtual void Update() = 0;
		virtual void Draw() = 0;

		virtual ~Shape() { };

	};

	class Polygon : public Shape
	{
	private:
		int segments;
		float radius;
	public:

		Polygon(float x = 0.5f, float y = 0.5f, float radius = 0.25f, int segments = 8);

		void Update();
		void Draw();

		~Polygon();

	};

	class Rectangle : public Shape
	{
	public:

		Rectangle(float x = 0.5f, float y = 0.5f, float height = 0.25f, float width = 0.5f);

		float height;
		float width;

		void Update();
		void Draw();

		~Rectangle();

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
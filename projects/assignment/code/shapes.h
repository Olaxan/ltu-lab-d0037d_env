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

		int vertexCount;

		Vector2D position = Vector2D(0, 0);
		Matrix2D rotation = Matrix2D::getRotationMatrix(0);

		AssignmentApp::Colour color = AssignmentApp::Colour(1, 0, 0);

		virtual void Connect();
		virtual void Globalize();
		virtual void Draw();

		virtual void Update() = 0;

		virtual ~Shape();

	};

	class Circle : public Shape
	{	
	public:
		Circle(float x = 0.5f, float y = 0.5f, float radius = 0.25f, int segments = 8, AssignmentApp::Colour color = AssignmentApp::Colour(1,0,0));

		int segments;
		float radius;

		void Update();

	};

	class Rectangle : public Shape
	{
	public:

		Rectangle(float x = 0.5f, float y = 0.5f, float height = 0.25f, float width = 0.5f, AssignmentApp::Colour color = AssignmentApp::Colour(1, 0, 0));

		float height;
		float width;

		void Update();

	};

	class Triangle : public Shape
	{
	public:

		Triangle(float x = 0.5f, float y = 0.5f, float base = 1, float height = 1, AssignmentApp::Colour color = AssignmentApp::Colour(1, 0, 0));

		float base;
		float height;

		void Update();

	};

	

}
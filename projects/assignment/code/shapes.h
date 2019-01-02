#pragma once

#include "matharr.h"
#include "config.h"
#include "assignmentapp.h"

namespace Assignment
{
	class Shape
	{
	protected:
		Vector2* _vertices;
		AssignmentApp::LineData* _lines;

	public:

		static const float PI_F;

		int vertexCount;

		Vector2 position = Vector2(0, 0);
		Matrix2 rotation = Matrix2::getRotationMatrix(0);

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
		Circle(float x = 0.5f, float y = 0.5f, float radius = 0.25f, int segments = 8,
			Matrix2 rotation = Matrix2::getRotationMatrix(0), 
			AssignmentApp::Colour color = AssignmentApp::Colour(1, 0, 0));

		int segments;
		float radius;

		void Update();

	};

	class Rectangle : public Shape
	{
	public:

		Rectangle(float x = 0.5f, float y = 0.5f, float height = 0.25f, float width = 0.5f,
			Matrix2 rotation = Matrix2::getRotationMatrix(0),
			AssignmentApp::Colour color = AssignmentApp::Colour(0, 1, 0));

		float height;
		float width;

		void Update();

	};

	class Triangle : public Shape
	{
	public:

		Triangle(float x = 0.5f, float y = 0.5f, float base = 1, float height = 1,
			Matrix2 rotation = Matrix2::getRotationMatrix(0),
			AssignmentApp::Colour color = AssignmentApp::Colour(0, 0, 1));

		float base;
		float height;

		void Update();

	};

	

}
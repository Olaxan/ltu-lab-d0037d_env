#pragma once

#include "matharr.h"
#include "config.h"
#include "assignmentapp.h"

namespace Assignment
{
	class Shape
	{
	protected:
		Vector3* _vertices;
		AssignmentApp::LineData* _lines;
		int vertexCount;

	public:

		static const float PI_F;

		Matrix3 transform = Matrix3();
		Vector3 velocity = Vector3();

		AssignmentApp::Colour color = AssignmentApp::Colour(1, 0, 0);

		virtual Vector3 getPosition();
		virtual void setPosition(Vector3 pos);

		virtual void Bounce(Vector3 norm);

		virtual void Connect();
		virtual void Globalize();
		virtual void Draw();

		virtual void Update() = 0;
		virtual void UpdatePosition();

		virtual ~Shape();

	};

	class Circle : public Shape
	{	
	public:
		Circle(float x = 0.5f, float y = 0.5f, float r = 0, float radius = 0.25f, int segments = 8,
			AssignmentApp::Colour color = AssignmentApp::Colour(1, 0, 0));

		int segments;
		float radius;

		void Update();

	};

	class Rectangle : public Shape
	{
	public:

		Rectangle(float x = 0.5f, float y = 0.5f, float r = 0, float height = 0.25f, float width = 0.5f,
			AssignmentApp::Colour color = AssignmentApp::Colour(0, 1, 0));

		float height;
		float width;

		void Update();

	};

	class Triangle : public Shape
	{
	public:

		Triangle(float x = 0.5f, float y = 0.5f, float r = 0, float base = 1, float height = 1,
			AssignmentApp::Colour color = AssignmentApp::Colour(0, 0, 1));

		float base;
		float height;

		void Update();

	};

	

}
#include "shapes.h"

namespace Assignment
{
	Triangle::Triangle(float x, float y, float base, float height, Matrix2 rotation, AssignmentApp::Colour color) : base(base), height(height)
	{
		this->_vertices = new Vector2[3]{ Vector2(), Vector2(), Vector2() };
		this->_lines = new AssignmentApp::LineData[3];
		this->position = Vector2(x, y);
		this->rotation = rotation;
		this->color = color;
		this->vertexCount = 3;

		this->Update();
	}

	void Triangle::Update()
	{

		float halfHeight = height / 2;
		float halfWidth = base / 2;

		_vertices[0].x(0);
		_vertices[0].y(-halfHeight);

		_vertices[1].x(halfWidth);
		_vertices[1].y(halfHeight);

		_vertices[2].x(-halfWidth);
		_vertices[2].y(halfHeight);

		this->Globalize();
		this->Connect();
	}

}
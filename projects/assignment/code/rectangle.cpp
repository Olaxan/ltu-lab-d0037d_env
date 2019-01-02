#include "shapes.h"

#include <cmath>

namespace Assignment
{
	Rectangle::Rectangle(float x, float y, float height, float width, Matrix2D rotation, AssignmentApp::Colour color) : height(height), width(width)
	{
		this->_vertices = new Vector2D[4]{ Vector2D(), Vector2D(), Vector2D(), Vector2D() };
		this->_lines = new AssignmentApp::LineData[4];
		this->position = Vector2D(x, y);
		this->rotation = rotation;
		this->color = color;
		this->vertexCount = 4;

		this->Update();
	}

	void Rectangle::Update()
	{

		float halfHeight = height / 2;
		float halfWidth = width / 2;

		_vertices[0].x(-halfWidth);
		_vertices[0].y(-halfHeight);

		_vertices[1].x(halfWidth);
		_vertices[1].y(-halfHeight);

		_vertices[2].x(halfWidth);
		_vertices[2].y(halfHeight);

		_vertices[3].x(-halfWidth);
		_vertices[3].y(halfHeight);

		this->Globalize();
		this->Connect();

	}

}
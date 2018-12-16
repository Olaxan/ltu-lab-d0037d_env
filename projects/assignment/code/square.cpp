#include "shapes.h"

#include <cmath>

namespace Assignment
{
	Rectangle::Rectangle(float x, float y, float height, float width) : height(height), width(width)
	{
		this->_vertices = new Vector2D[4]{ Vector2D(), Vector2D(), Vector2D(), Vector2D() };
		this->_lines = new AssignmentApp::LineData[4];
		this->position = Vector2D(x, y);
	}

	void Rectangle::Update()
	{

		float halfHeight = height / 2;
		float halfWidth = width / 2;

		for (int i = 0; i < 4; i++)
		{

		}

	}

	void Rectangle::Draw()
	{
		for (int i = 0; i < 4; i++)
		{
			AssignmentApp::DrawLine(_lines[i]);
		}
	}

	Rectangle::~Rectangle()
	{
		delete[] _vertices;
		delete[] _lines;
	}
}
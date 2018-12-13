#include "shapes.h"

namespace Assignment
{
	Circle::Circle(float x, float y, float radius, int segments)
	{
		this->_vertices = new Vector2D[segments];
		this->_lines = new AssignmentApp::LineData[segments];
		for (int i = 0; i < segments; i++)
		{
			_vertices[i] = Vector2D();
		}
		this->position = Vector2D(x, y);
		this->segments = segments;
		this->Update();
	}
	void Circle::Update()
	{
		float delta = 360 / segments;

		for (int i = 0; i < segments + 1; i++)
		{
			if (i < segments)
			{
				_vertices[i].x = cos(i + delta) * radius;
				_vertices[i].y = sin(i + delta) * radius;
				_vertices[i] *= rotation;
				_vertices[i] += position;
			}

			if (i > 0)
			{
				int j = i - 1;
				_lines[j].x1 = _vertices[i - 1].x;
				_lines[j].y1 = _vertices[i - 1].y;
				_lines[j].x2 = _vertices[i].x;
				_lines[j].y2 = _vertices[i].y;
				_lines[j].c1 = color;
				_lines[j].c2 = color;
			}
		}
	}
	void Circle::Draw()
	{
		for (int i = 0; i < segments; i++)
		{
			AssignmentApp::DrawLine(_lines[i]);
		}
	}

	Circle::~Circle()
	{
	}
}
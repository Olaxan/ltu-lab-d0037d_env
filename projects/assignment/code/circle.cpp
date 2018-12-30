#include "shapes.h"

#include <iostream>



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
		this->vertexCount = segments;
		this->radius = radius;
		this->Update();
	}
	void Circle::Update()
	{
		float delta = (2 * Shape::PI_F) / vertexCount;

		for (int i = 0; i < vertexCount; i++)
		{
			_vertices[i].x(cos(i * delta) * radius);
			_vertices[i].y(sin(i * delta) * radius);
		}

		this->Globalize();
		this->Connect();
	}

}
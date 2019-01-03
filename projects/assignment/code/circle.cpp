#include "shapes.h"

#include <iostream>



namespace Assignment
{
	Circle::Circle(float x, float y, float r, float radius, int segments, AssignmentApp::Colour color)
	{
		this->_vertices = new Vector3[segments];
		this->_lines = new AssignmentApp::LineData[segments];
		for (int i = 0; i < segments; i++)
		{
			_vertices[i] = Vector3(true);
		}
		this->transform = Matrix3::getRotationMatrix(r) * Matrix3::getTranslation(Vector3(x, y, 1));
		this->vertexCount = segments;
		this->radius = radius;
		this->color = color;

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
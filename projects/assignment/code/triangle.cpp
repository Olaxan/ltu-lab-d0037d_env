#include "shapes.h"

#include <iostream>

namespace Assignment
{
	Triangle::Triangle(float x, float y, float r, float base, float height, AssignmentApp::Colour color) : base(base), height(height)
	{
		this->_vertices = new Vector3[3]{ Vector3(true), Vector3(true), Vector3(true) };
		this->_lines = new AssignmentApp::LineData[3];
		this->transform = Matrix3::getRotationMatrix(r) * Matrix3::getTranslation(Vector3(x, y, 1));
		this->color = color;
		this->vertexCount = 3;

		this->Update();
	}

	void Triangle::Update()
	{
		this->UpdatePosition();

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
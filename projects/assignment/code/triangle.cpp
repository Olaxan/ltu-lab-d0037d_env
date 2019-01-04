#include "shapes.h"

#include <iostream>

namespace Assignment
{
	Triangle::Triangle(float x, float y, float r, float base, float height, AssignmentApp::Colour color) : base(base), height(height)
	{
		this->Init(x, y, r, 3, color);
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

		this->Bounds(-1, 1, -1, 1, boundsMode);
		this->UpdatePosition();
		this->Globalize();
		this->Connect();
	}

}
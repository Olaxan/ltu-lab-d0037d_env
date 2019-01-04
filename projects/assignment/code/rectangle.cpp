#include "shapes.h"

#include <cmath>

namespace Assignment
{
	Rectangle::Rectangle(float x, float y, float r, float height, float width, AssignmentApp::Colour color) : height(height), width(width)
	{
		this->Init(x, y, r, 4, color);
		this->Update();
	}

	float Rectangle::GetNarrowPhysicsDistance()
	{
		return sqrt(pow(width / 2, 2) + pow(height/2, 2)) * 1.1;
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

		this->Bounds(-1, 1, -1, 1, boundsMode);
		this->StepForward();
		this->Globalize();
		this->Connect();

	}

}
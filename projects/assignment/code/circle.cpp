#include "shapes.h"

#include <iostream>



namespace Assignment
{
	Circle::Circle(float x, float y, float r, float radius, int segments, AssignmentApp::Colour color) : radius(radius)
	{
		this->Init(x, y, r, segments, color);
		this->Update();
	}

	float Circle::GetNarrowPhysicsDistance()
	{
		return radius * 1.5;
	}

	void Circle::Update()
	{
		float delta = (2 * Shape::PI_F) / vertexCount;

		for (int i = 0; i < vertexCount; i++)
		{
			_vertices[i].x(cos(i * delta) * radius);
			_vertices[i].y(sin(i * delta) * radius);
		}

		this->Bounds(-1, 1, -1, 1, boundsMode);
		this->StepForward();
		this->Globalize();
		this->Connect();
	}

	bool Circle::PointInside(const Vector3& point)
	{
		return (Vector3::dist(GetPosition(), point) <= radius);
	}
}
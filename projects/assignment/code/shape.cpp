#include "shapes.h"

namespace Assignment
{
	const float Shape::PI_F = 3.14159265358979f;

	void Shape::Connect()
	{

		for (int i = 0; i < vertexCount - 1; i++)
		{
			_lines[i].x1 = _vertices[i].x();
			_lines[i].y1 = _vertices[i].y();
			_lines[i].x2 = _vertices[i + 1].x();
			_lines[i].y2 = _vertices[i + 1].y();
			_lines[i].c1 = color;
			_lines[i].c2 = color;
		}

		_lines[vertexCount - 1].x1 = _vertices[0].x();
		_lines[vertexCount - 1].y1 = _vertices[0].y();
		_lines[vertexCount - 1].x2 = _vertices[vertexCount - 1].x();
		_lines[vertexCount - 1].y2 = _vertices[vertexCount - 1].y();
		_lines[vertexCount - 1].c1 = color;
		_lines[vertexCount - 1].c2 = color;
	}

	void Shape::Globalize()
	{
		for (int i = 0; i < vertexCount; i++)
		{
			_vertices[i] *= rotation;
			_vertices[i] += position;
		}
	}

	void Shape::Draw()
	{
		for (int i = 0; i < vertexCount; i++)
		{
			AssignmentApp::DrawLine(_lines[i]);
		}
	}

	Shape::~Shape()
	{
		delete[] _lines;
		delete[] _vertices;
	}
}
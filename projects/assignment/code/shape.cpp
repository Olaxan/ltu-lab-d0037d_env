#include "shapes.h"

#include <iostream>

namespace Assignment
{
	const float Shape::PI_F = 3.14159265358979f;

	Vector3 Shape::getPosition()
	{
		return Vector3(transform(2, 0), transform(2, 1), transform(2, 2));
	}

	void Shape::setPosition(Vector3 pos)
	{
		this->transform(2, 0) = pos.x();
		this->transform(2, 1) = pos.y();
		this->transform(2, 2) = pos.z();
	}

	void Shape::Reflect(Vector3 norm)
	{
		velocity = velocity.getReflection(norm);
	}

	void Shape::Bounds(float left, float right, float bottom, float top, int mode)
	{
		if (mode == None)
			return;

		Vector3 pos = getPosition();

		if (pos.x() + velocity.x() < left)
		{
			if (mode == Wrap)
				pos.x(right);
			else
			{
				pos.x(left);
				Reflect(Vector3(1, 0, 0));
			}
		}
		else if (pos.x() + velocity.x() > right)
		{
			if (mode == Wrap)
				pos.x(left);
			else
			{
				pos.x(right);
				Reflect(Vector3(-1, 0, 0));
			}
		}

		if (pos.y() + velocity.y() < bottom)
		{
			if (mode == Wrap)
				pos.y(top);
			else
			{
				pos.y(bottom);
				Reflect(Vector3(0, 1, 0));
			}
		}
		else if (pos.y() + velocity.y() > top)
		{
			if (mode == Wrap)
				pos.y(bottom);
			else
			{
				pos.y(top);
				Reflect(Vector3(0, -1, 0));
			}
		}

		setPosition(pos);
	}

	void Shape::PreCalc()
	{
		int i;
		int j = vertexCount - 1;

		for (i = 0; i < vertexCount; i++)
		{
			if (_vertices[j].y() == _vertices[i].y())
			{
				_constant[i] = _vertices[i].x();
				_multiple[i] = 0;
			}
			else
			{
				_constant[i] = _vertices[i].x() - (_vertices[i].y() * _vertices[j].x()) / (_vertices[j].y() - _vertices[i].y()) + (_vertices[i].y() * _vertices[i].x()) / (_vertices[j].y() - _vertices[i].y());
				_multiple[i] = (_vertices[j].x() - _vertices[i].x()) / (_vertices[j].y() - _vertices[i].y());
			}

			j = i;
		}
	}

	bool Shape::PointInside(float x, float y)
	{
		int i;
		int j = vertexCount - 1;
		bool  oddNodes = false;

		for (i = 0; i < vertexCount; i++)
		{
			if ((_vertices[i].y() < y && _vertices[j].y() >= y || _vertices[j].y() < y && _vertices[i].y() >= y))
			{
				oddNodes ^= (y*_multiple[i] + _constant[i] < x);
			}

			j = i;
		}

		return oddNodes;
	}

	bool Shape::Intersect(Shape * obj)
	{
		PreCalc();

		for (int i = 0; i < obj->vertexCount; i++)
		{
			if (PointInside(obj->_vertices[i].x(), obj->_vertices[i].y()))
				return true;
		}

		return false;
	}

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
			_vertices[i] *= transform;
		}
	}

	void Shape::Draw()
	{
		for (int i = 0; i < vertexCount; i++)
		{
			AssignmentApp::DrawLine(_lines[i]);
		}
	}

	void Shape::Init(float x, float y, float r, int vertices, AssignmentApp::Colour color)
	{
		this->_vertices = new Vector3[vertices];
		this->_constant = new float[vertices];
		this->_multiple = new float[vertices];
		this->_lines = new AssignmentApp::LineData[vertices];
		for (int i = 0; i < vertices; i++)
		{
			_vertices[i] = Vector3(true);
		}
		this->transform = Matrix3::getRotationMatrix(r) * Matrix3::getTranslation(Vector3(x, y, 1));
		this->vertexCount = vertices;
		this->color = color;
	}

	void Shape::UpdatePosition()
	{
		this->setPosition(getPosition() + velocity);
	}

	Shape::~Shape()
	{
		delete[] _lines;
		delete[] _vertices;
		delete[] _constant;
		delete[] _multiple;
	}
}
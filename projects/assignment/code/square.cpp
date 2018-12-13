#include "shapes.h"

namespace Assignment
{
	Square::Square(float x, float y, float size)
	{
		this->_vertices = new Vector2D[4]{ Vector2D(), Vector2D(), Vector2D(), Vector2D() };
		this->position = Vector2D(x, y);
		this->size = size;
	}

	void Square::Update()
	{

		float yTop = position.y - size / 2;
		float xRight = position.x + size / 2;
		float yBottom = position.y + size / 2;
		float xLeft = position.x - size / 2;

		_vertices[0].x = xLeft;
		_vertices[0].y = yTop;

		_vertices[1].x = xRight;
		_vertices[1].y = yTop;

		_vertices[2].x = xLeft;
		_vertices[2].y = yBottom;

		_vertices[3].x = xRight;
		_vertices[3].y = yBottom;

	}

	void Square::Draw()
	{
		
	}

	Square::~Square() { delete[] _vertices; }
}
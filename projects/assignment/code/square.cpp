#include "shapes.h"

namespace Assignment
{
	Square::Square(float x, float y, float size)
	{
		position = Vector2D(x, y);
		this->size = size;
	}

	void Square::Update()
	{
	}

	void Square::Draw()
	{
		float yTop = position.y - size / 2;;
		float xRight = position.x + size / 2;;
		float yBottom = position.y + size / 2;
		float xLeft = position.x - size / 2;

		AssignmentApp::LineData top, right, bottom, left;

		top.y1 = yTop;
		top.y2 = yTop;
		top.x1 = xLeft;
		top.x2 = xRight;

		bottom.y1 = yBottom;
		bottom.y2 = yBottom;
		bottom.x1 = xLeft;
		bottom.x2 = xRight;

		left.y1 = yTop;
		left.y2
		

	}

	Square::~Square() { }
}
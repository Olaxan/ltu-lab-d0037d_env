#pragma once

#include <vector>
#include <algorithm>

namespace Assignment
{
	class Shape;
	class GameManager
	{
	public:

		GameManager();

		static int time;
		std::vector<Shape* > gameObjects;

		void addObject(Shape *obj);
		void RemoveByType(const type_info &type);

		void doCollision();

		void step();

		virtual ~GameManager() { gameObjects.clear(); }
	};
}



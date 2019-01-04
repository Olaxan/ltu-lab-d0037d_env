#include "gamemgr.h"

namespace Assignment
{

	int GameManager::time = 0;

	GameManager::GameManager()
	{
	}

	void GameManager::addObject(Shape * obj)
	{
		gameObjects.push_back(obj);
	}

	void GameManager::RemoveByType(const type_info & type)
	{
		std::vector<Shape*> copy;
		std::copy_if(gameObjects.begin(), gameObjects.end(), std::back_inserter(copy), [&type](Shape* s) {return typeid(*s) != type; });
		gameObjects = copy;
	}

	void GameManager::doCollision()
	{
		Shape* obj;
		Shape* other;

		for (int i = 0; i < gameObjects.size(); i++)
		{
			obj = gameObjects[i];
			if (obj->solid)
			{
				for (int j = 0; j < gameObjects.size(); j++)
				{
					other = gameObjects[j];
					if (obj->Intersect(other))
					{
						Vector3 normal = (obj->getPosition() - other->getPosition());
						normal = normal * (1 / normal.norm());
						obj->Reflect(normal);
					}
				}
			}
		}
	}

	void GameManager::step()
	{
		time++;

		doCollision();

		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Update();
			gameObjects[i]->Draw();
		}
	}

	GameManager::~GameManager()
	{
	}

}


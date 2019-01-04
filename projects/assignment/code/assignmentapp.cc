//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include "shapes.h"

#include <iostream>
#include <typeinfo>
#include <random>

namespace Assignment
{

	int AssignmentApp::time = 0;

	AssignmentApp::AssignmentApp()
	{
		// empty
	}

	double AssignmentApp::randf(double min, double max)
	{
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_real_distribution<double> distr(min, max);
		return distr(eng);
	}

	double AssignmentApp::randf()
	{
		return randf(0, 1);
	}

	AssignmentApp::~AssignmentApp()
	{
		gameShapes.clear();
	}

	void AssignmentApp::KeyEvent(int key, int action, int mod)
	{
		switch (key)
		{
			case GLFW_KEY_1:
			{
				if (action == 1)
				{
					Shape* c = new Triangle(randf(-1, 1), randf(-1, 1), randf(0, Shape::PI_F * 2), randf(0.05, 0.3), randf(0.05, 0.1), Colour::random());
					c->velocity = Vector3(0.002, 0.002, 0);
					c->boundsMode = Shape::bndBounce;
					c->solid = true;
					gameShapes.push_back(c);

					break;
				}
					
				break;
			}
			case GLFW_KEY_2:
			{
				if (action == 1)
				{
					Shape* c = new Rectangle(randf(-1, 1), randf(-1, 1), randf(0, Shape::PI_F * 2), randf(0.05, 0.3), randf(0.05, 0.1), Colour::random());
					c->velocity = Vector3(0.002, 0.002, 0);
					c->boundsMode = Shape::bndBounce;
					c->solid = true;
					gameShapes.push_back(c);

					break;
				}
					
				break;
			}
			case GLFW_KEY_3:
			{
				if (action == 1)
				{
					Shape* c = new Circle(randf(-1, 1), randf(-1, 1), randf(0, Shape::PI_F * 2), randf(0.05, 0.3), 8, Colour::random());
					c->velocity = Vector3(0.002, 0.002, 0);
					c->boundsMode = Shape::bndBounce;
					c->solid = true;
					gameShapes.push_back(c);

					break;
				}
					
				break;
			}
			case GLFW_KEY_Q:
			{
				RemoveByType(typeid(Triangle));
				break;
			}
			case GLFW_KEY_W:
			{
				RemoveByType(typeid(Rectangle));
				break;
			}
			case GLFW_KEY_E:
			{
				RemoveByType(typeid(Circle));
				break;
			}
			case GLFW_KEY_A:
			case GLFW_KEY_LEFT:
			{
				gameShapes[0]->velocity = Vector3(-0.005, 0, 0);
				break;
			}
			case GLFW_KEY_D:
			case GLFW_KEY_RIGHT:
			{
				gameShapes[0]->velocity = Vector3(0.005, 0, 0);
				break;
			}
		}
	}

	void AssignmentApp::RemoveByType(const type_info & type)
	{
		std::vector<Shape*> copy;
		std::copy_if(gameShapes.begin(), gameShapes.end(), std::back_inserter(copy), [&type](Shape* s) {return typeid(*s) != type; });
		gameShapes = copy;
	}

	void AssignmentApp::Setup()
	{
		Display::Window* win = this->GetWindow();
		win->SetKeyPressFunction([this](int key, int, int action, int mod) {this->KeyEvent(key, action, mod); });
	}

	void AssignmentApp::Update()
	{
		time++;

		//std::cout << "\rTime: " << time;

		Shape* obj;
		Shape* other;

		for (int i = 0; i < gameShapes.size(); i++)
		{
			obj = gameShapes[i];

			for (int j = 0; j < gameShapes.size(); j++)
			{
				other = gameShapes[j];

				if (i == j)
					continue;

				if (obj->solid && other->solid && obj->Intersect(other, true))
					obj->Bounce(other);
			}

			obj->Update();
			obj->Draw();
		}
	}
}

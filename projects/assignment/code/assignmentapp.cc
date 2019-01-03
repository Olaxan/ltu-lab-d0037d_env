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
		renderQueue.clear();
	}

	void AssignmentApp::KeyEvent(int key, int action, int mod)
	{
		switch (key)
		{
			case GLFW_KEY_1:
			{
				if (action == 1)
					renderQueue.push_back(new Triangle(randf(-1, 1), randf(-1, 1), randf(0, 2 * Shape::PI_F), randf(), randf(), Colour::random()));
					
				break;
			}
			case GLFW_KEY_2:
			{
				if (action == 1)
					renderQueue.push_back(new Rectangle(randf(-1, 1), randf(-1, 1), randf(0, 2 * Shape::PI_F), randf(), randf(), Colour::random()));
					
				break;
			}
			case GLFW_KEY_3:
			{
				if (action == 1)
					renderQueue.push_back(new Circle(randf(-1, 1), randf(-1, 1), randf(0, 2 * Shape::PI_F), randf(), 6 + rand() % 10, Colour::random()));
					
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
		}
	}

	void AssignmentApp::RemoveByType(const type_info & type)
	{
		std::vector<Shape*> copy;
		std::copy_if(renderQueue.begin(), renderQueue.end(), std::back_inserter(copy), [&type](Shape* s) {return typeid(*s) != type; });
		renderQueue = copy;
	}

	void AssignmentApp::Setup()
	{
		Display::Window* win = this->GetWindow();
		win->SetKeyPressFunction([this](int key, int, int action, int mod) {this->KeyEvent(key, action, mod); });
	}

	void AssignmentApp::Update()
	{
		time++;

		for (int i = 0; i < renderQueue.size(); i++)
		{
			renderQueue[i]->Draw();
		}
	}
}

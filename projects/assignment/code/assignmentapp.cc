//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include "shapes.h"

#include <iostream>

namespace Assignment
{

	int AssignmentApp::time = 0;

	AssignmentApp::AssignmentApp()
	{
		// empty
	}

	float AssignmentApp::randf()
	{
		return rand() / (RAND_MAX + 1.);
	}

	AssignmentApp::~AssignmentApp()
	{
		renderQueue.clear();
	}

	void AssignmentApp::KeyEvent(int key, int action, int mod)
	{
		switch (key)
		{
			case '1':
			{
				if (action == 1)
				{
					Colour c = Colour::random();
					Triangle* t = new Triangle(randf(), randf(), randf(), randf());
					t->color = c;
					renderQueue.push_back(t);
					break;
				}
			}
			case '2':
			{
				if (action == 1)
				{
					Colour c = Colour::random();
					Rectangle* t = new Rectangle(randf(), randf(), randf(), randf());
					t->color = c;
					renderQueue.push_back(t);
					break;
				}
			}
			case '3':
			{
				if (action == 1)
				{
					Colour c = Colour::random();
					Circle* t = new Circle(randf(), randf(), randf(), 6 + rand() % 10);
					t->color = c;
					renderQueue.push_back(t);
					break;
				}
			}
		}
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
			renderQueue[i]->position.y(0.25f * sin((i + 1) * 0.005f * time));
			renderQueue[i]->rotation = Matrix2D::getRotationMatrix(0.005f * time * (1 - i));
			renderQueue[i]->Update();
		}
	}
}

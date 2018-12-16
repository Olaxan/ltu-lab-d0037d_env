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

	//------------------------------------------------------------------------------
	/**
	*/
	AssignmentApp::AssignmentApp()
	{
		// empty
	}

	//------------------------------------------------------------------------------
	/**
	*/
	AssignmentApp::~AssignmentApp()
	{
		renderQueue.clear();
	}

	//------------------------------------------------------------------------------
	/**
	*/
	void 
	AssignmentApp::Setup()
	{
		renderQueue.push_back(new Rectangle(-0.5, 0, 0.25F));
		renderQueue.push_back(new Polygon(0, 0, 0.25F, 4));
		renderQueue.push_back(new Polygon(0.5, 0, 0.25F, 3));

		renderQueue[0]->color = AssignmentApp::Colour(1, 0, 0);
		renderQueue[1]->color = AssignmentApp::Colour(0, 1, 0);
		renderQueue[2]->color = AssignmentApp::Colour(0, 0, 1);
	}
	//------------------------------------------------------------------------------
	/**
	*/
	void
	AssignmentApp::Update()
	{
		time++;

		for (int i = 0; i < renderQueue.size(); i++)
		{
			renderQueue[i]->Draw();
			renderQueue[i]->position.y(0.25f * sin((i + 1) *0.05f * time));
			renderQueue[i]->rotation = Matrix2D::getRotationMatrix(0.05f * time * (1 - i));
			renderQueue[i]->Update();
		}
	}
}

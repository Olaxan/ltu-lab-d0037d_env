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
	// empty
}

//------------------------------------------------------------------------------
/**
*/
void 
AssignmentApp::Setup()
{
	renderQueue.push_back(new Circle(-1, 0, 0.25F, 3));
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
		renderQueue[i]->position = Vector2D(0.5f * sin(0.005f * time), 0.5f * cos(0.005f * time));
		renderQueue[i]->rotation = Matrix2D::getRotationMatrix(0.005f * time);
		renderQueue[i]->Update();
	}
}

} // namespace Assignment

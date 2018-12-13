//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"

namespace Assignment
{

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
	renderQueue.push_back(&Triangle(0.3F, 0.3F));
	renderQueue.push_back(&Square(0.5F, 0.5F, 0.25F));
	renderQueue.push_back(&Circle(0.75F, 0.75F, 0.3F));
}
//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::Update()
{
	for (int i = 0; i < renderQueue.size(); i++)
	{
		renderQueue[i]->Draw();
	}
}

} // namespace Assignment

//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "shapes.h"
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
	Triangle tri = Triangle(0.3F, 0.3F);
	Square sqr = Square(0.5F);
	Circle cir = Circle(0.3F);
}
//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::Update()
{
	// demo line drawing code
	
}

} // namespace Assignment

#pragma once
//------------------------------------------------------------------------------
/**
	Application class used for Assignment applications.
	Based on 2D app
	
	(C) 2015-2017 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"
#include "2d/2dapp.h"

#include <vector>

namespace Assignment
{
	class Shape;
	class AssignmentApp : public App2D::BaseApp
	{
	public:
		static AssignmentApp& GetInstance()
		{
			static AssignmentApp instance;
			return instance;
		}

		static int time;

		std::vector<Shape*> renderQueue;

		/// destructor
		~AssignmentApp();

		/// handle keypresses
		void KeyEvent(int key, int action, int mod);

		/// initialize, create shapes etc
		void Setup();

		/// update app, draw lines etc
		void Update();

		/// removes all objects of type from renderqueue
		void RemoveByType(const type_info &type);

		/// line drawing function
		static void DrawLine(const LineData & line);

	private:
		/// constructor hidden because it is a singleton
		AssignmentApp();
		/// also hidden because of the singleton
		AssignmentApp(AssignmentApp const &);
		/// also hidden because of the singleton
		void operator=(AssignmentApp const &);
		/// hidden because it's stupid
		double randf();
		double randf(double min, double max);

	};

	//------------------------------------------------------------------------------
	/**
	*/
	inline void 
	AssignmentApp::DrawLine( const LineData & line )
	{
		AssignmentApp::GetInstance().AddLine(line);
	}
} // namespace Assignment
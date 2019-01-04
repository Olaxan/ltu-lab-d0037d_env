#pragma once

#include "matharr.h"
#include "config.h"
#include "assignmentapp.h"

namespace Assignment
{
	class Shape
	{
	protected:
		Vector3* _vertices;
		AssignmentApp::LineData* _lines;
		float* _constant;
		float* _multiple;
		int vertexCount;

	public:

		static const float PI_F;
		enum bounds { bndNone, bndWrap, bndBounce };

		Matrix3 transform = Matrix3();
		Vector3 velocity = Vector3();

		AssignmentApp::Colour color = AssignmentApp::Colour(1, 0, 0);

		int boundsMode = bndNone;
		bool solid = false;
		bool rigid = false;

		virtual Vector3 GetPosition();
		virtual void SetPosition(Vector3 pos);

		virtual void Reflect(Vector3 norm);
		virtual void Bounce(Shape* obj);
		virtual void Bounds(float left, float right, float bottom, float top, int mode);

		virtual void PrecalcVertexBounds();
		virtual bool PointInside(const Vector3& point);
		virtual bool Intersect(Shape* obj, bool nextStep = false);

		virtual void Init(float x, float y, float r, int vertices, AssignmentApp::Colour color);
		virtual void Connect();
		virtual void Globalize();

		virtual void StepForward();
		virtual void StepForward(const Vector3& step);
		virtual void StepBackward();
		virtual void StepBackward(const Vector3& step);

		virtual float GetNarrowPhysicsDistance() = 0;
		virtual void Update() = 0;
		virtual void Draw();

		virtual ~Shape();

	};

	class Circle : public Shape
	{	
	public:
		Circle(float x = 0.5f, float y = 0.5f, float r = 0, float radius = 0.25f, int segments = 8,
			AssignmentApp::Colour color = AssignmentApp::Colour(1, 0, 0));

		int segments;
		float radius;

		bool PointInside(const Vector3& point);

		float GetNarrowPhysicsDistance();
		void Update();

	};

	class Rectangle : public Shape
	{
	public:

		Rectangle(float x = 0.5f, float y = 0.5f, float r = 0, float height = 0.25f, float width = 0.5f,
			AssignmentApp::Colour color = AssignmentApp::Colour(0, 1, 0));

		float height;
		float width;

		float GetNarrowPhysicsDistance();
		void Update();

	};

	class Triangle : public Shape
	{
	public:

		Triangle(float x = 0.5f, float y = 0.5f, float r = 0, float base = 1, float height = 1,
			AssignmentApp::Colour color = AssignmentApp::Colour(0, 0, 1));

		float base;
		float height;

		float GetNarrowPhysicsDistance();
		void Update();

	};

	

}
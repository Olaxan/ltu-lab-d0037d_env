#pragma once

class GameObject
{
public:
	GameObject();


	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~GameObject();
};


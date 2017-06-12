<<<<<<< .mine
#pragma once
#include "GameObject.h"

class Color;

class Paint : GameObject
{
public:
	Paint();
	~Paint();
	void Start();
	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);
	void OnCollision(GameObject & other);
private:
	float Speed;
	Color* color;
};

||||||| .r0
=======
#pragma once
#include "GameObject.h"

class Color;

class Paint : GameObject
{
public:
	Paint();
	~Paint();
	void Start();
	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);
private:
	float Speed;
	Color* color;
};

>>>>>>> .r2

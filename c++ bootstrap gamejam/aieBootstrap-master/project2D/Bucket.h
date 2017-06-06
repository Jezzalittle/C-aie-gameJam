#pragma once
#include "GameObject.h"
#include "Application2D.h"

class Bucket : GameObject
{
public:
	Bucket(std::string textureName, Vector2 pos);
	~Bucket();
	
	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

private:
	
	aie::Input* input;
	bool dragging;


};


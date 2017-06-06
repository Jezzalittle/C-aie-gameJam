#pragma once
#include "Application2D.h"
#include "Scene.h"
#include <vector>

class Bucket;
class Paint;
class GameObject;

class GameScene : public Scene
{
public:
	GameScene();

	void StartUp();
	void Update(float deltaTime);
	void Draw(aie::Renderer2D* randerer);


	~GameScene();
private:
	std::vector <GameObject*> GOarray; 
	
	Bucket* blueBucket;
	Bucket* greenBucket;
	Bucket* pinkBucket;
	Bucket* redBucket;



	float gameTimer;

};


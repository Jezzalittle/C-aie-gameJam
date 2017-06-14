#pragma once
#include "Application2D.h"
#include "Scene.h"
#include <vector>
#include <Windows.h>
#include "Vector2.h"

class Bucket;
class Paint;
class GameObject;


struct SharedData
{
	std::string bucketName;
	Vector2 sharedValue;
	bool enterPressed;
};


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

	std::string oldBucketName;
	Vector2 oldVec;
	SharedData* data;

	float gameTimer;

};



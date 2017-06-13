#include "GameScene.h"
#include "GameObject.h"
#include "GameManager.h"
#include "Paint.h"
#include "Bucket.h"

GameScene::GameScene()
{
	nameOfScene = "GameScene";
	GameManager::instance().sm->CreateScene(this);
	gameTimer = 0;
}

void GameScene::StartUp()
{
	std::cout << nameOfScene << std::endl;
	blueBucket = new Bucket("./textures/BlueBucket.png", Vector2(15, 15), "BlueBucket");
	greenBucket = new Bucket("./textures/GreenBucket.png", Vector2(165, 15), "GreenBucket");
	pinkBucket = new Bucket("./textures/PinkBucket.png", Vector2(265, 15), "PinkBucket");
	redBucket = new Bucket("./textures/RedBucket.png", Vector2(365, 15), "RedBucket");

}

void GameScene::Update(float deltaTime)
{
	gameTimer += deltaTime;
	GOarray = GameManager::instance().om->getGOArray();
	for (size_t i = 0; i < GOarray.size(); i++)
	{
		GOarray[i]->Update(deltaTime);
	}
	if (gameTimer >= 3)
	{
		new Paint();
		gameTimer = 0;
	}
	GameManager::instance().cm->UpdateCollision(GOarray);
}

void GameScene::Draw(aie::Renderer2D* renderer)
{
	GOarray = GameManager::instance().om->getGOArray();
	for (size_t i = 0; i < GOarray.size(); i++)
	{
		if(GOarray[i] != nullptr)
		{
			GOarray[i]->Draw(renderer);
		}

	}
}


GameScene::~GameScene()
{
}

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
	blueBucket = new Bucket("./textures/BlueBucket.png", Vector2(15, 15));
	greenBucket = new Bucket("./textures/GreenBucket.png", Vector2(165, 15));
	pinkBucket = new Bucket("./textures/PinkBucket.png", Vector2(265, 15));
	redBucket = new Bucket("./textures/RedBucket.png", Vector2(365, 15));

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
	for (size_t i = 0; i < GOarray.size(); i++)
	{
		GOarray[i]->Draw(renderer);
	}
}


GameScene::~GameScene()
{
}

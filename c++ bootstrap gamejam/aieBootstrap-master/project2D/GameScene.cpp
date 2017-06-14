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
	blueBucket = new Bucket("./textures/BlueBucket.png", Vector2(15, 15), "blue");
	greenBucket = new Bucket("./textures/GreenBucket.png", Vector2(165, 15), "green");
	pinkBucket = new Bucket("./textures/PinkBucket.png", Vector2(265, 15), "pink");
	redBucket = new Bucket("./textures/RedBucket.png", Vector2(365, 15), "red");

	HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");

	data = (SharedData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(SharedData));


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

	if (data != nullptr)
	{
		if (oldBucketName != data->bucketName || oldVec != data->sharedValue)
		{
			if (data->enterPressed == true)
			{
				data->enterPressed = false;
				oldBucketName = data->bucketName;
				oldVec = data->sharedValue;


				for (size_t i = 0; i < GOarray.size(); i++)
				{
					if (GOarray[i]->GetTag() == oldBucketName)
					{
						GOarray[i]->SetPosition(oldVec);
					}
				}
			}
		}
	}



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

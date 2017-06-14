#include "Paint.h"
#include <random>
#include "Application2D.h"
#include "GameManager.h"
#include "TextureManager.h"
#include <time.h>

Paint::Paint() : GameObject()
{
	srand(time(NULL));
	tag = "paint";
	color = GameManager::instance().tm->GetRandomColor();
	radius = 5;
	Start();
	radius = 5;
}


Paint::~Paint()
{
}

void Paint::Start()
{

	GameManager& gm = GameManager::instance();
	transform.SetPosition(Vector2((rand() % (int)gm.screenRes.x), gm.screenRes.y - 10));
	if (color == GameManager::instance().tm->GetRed())
	{
		colorName  = "red";
	}
	else if (color == GameManager::instance().tm->GetBlue())
	{
		colorName = "blue";
	}
	else if (color == GameManager::instance().tm->GetGreen())
	{
		colorName = "green";
	}
	else if (color == GameManager::instance().tm->GetPink())
	{
		colorName = "pink";
	}
}

void Paint::Update(float deltaTime)
{
	transform.Translate(Vector2(0.0f, -1.0f));
}

void Paint::Draw(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(color->r, color->g, color->b);
	renderer->drawCircle(transform.GetPosition().x, transform.GetPosition().y, 5);
}

void Paint::OnCollision(GameObject & other)
{
	std::cout << " " << std::endl;
	if (other.GetTag() == colorName)
	{
		delete(this);
	}
}
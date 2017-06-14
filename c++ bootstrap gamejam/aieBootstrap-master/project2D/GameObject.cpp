#include "GameObject.h"
#include "GameManager.h"
#include <algorithm>
#include <vector>
GameObject::GameObject()
{
	transform = Transform();
	GameManager::instance().om->addGameObject(this);

}



GameObject::~GameObject()
{
	std::cout << GameManager::instance().om->getGOArray().size() << std::endl;

	auto gameObjectFound = std::find(GameManager::instance().om->getGOArray().begin(), GameManager::instance().om->getGOArray().end(), this);
	GameManager::instance().om->getGOArray().erase(gameObjectFound);

	std::cout << " " << std::endl;
	std::cout << GameManager::instance().om->getGOArray().size() << std::endl;
}


void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw(aie::Renderer2D * randerer)
{
}

void GameObject::OnCollision(GameObject & other)
{
}

float GameObject::GetRadius()
{
	return radius;
}

void GameObject::SetRadius(float a_radius)
{
	radius = a_radius;
}

Vector2 GameObject::GetPosition()
{
	return transform.GetPosition();
}

void GameObject::SetPosition(Vector2 a_vec)
{
	transform.SetPosition(a_vec);
}

std::string GameObject::GetTag()
{
	return tag;
}

void GameObject::SetTag(std::string a_tag)
{
	tag = a_tag;
}


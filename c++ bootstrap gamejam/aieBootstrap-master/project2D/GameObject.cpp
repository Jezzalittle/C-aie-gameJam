#include "GameObject.h"
#include "GameManager.h"
#include <vector>
#include <algorithm>

GameObject::GameObject()
{
	transform = Transform();
	GameManager::instance().om->addGameObject(this);
}


GameObject::~GameObject()
{
	std::cout << GameManager::instance().om->getGOArray().size() << std::endl;
	GameManager::instance().om->getGOArray().erase(std::remove(GameManager::instance().om->getGOArray().begin(), GameManager::instance().om->getGOArray().end(), this), GameManager::instance().om->getGOArray().end());
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

std::string GameObject::GetTag()
{
	return tag;
}

void GameObject::SetTag(std::string a_tag)
{
	tag = a_tag;
}


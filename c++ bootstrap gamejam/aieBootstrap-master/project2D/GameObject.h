#pragma once
#include "Application2D.h"
#include "Transform.h"

class GameManager;
class Scene;
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Update(float deltaTime);
	virtual void Draw(aie::Renderer2D* randerer);
	virtual void OnCollision(GameObject& other);

	float GetRadius();
	void SetRadius(float a_radius);

	Vector2 GetPosition();
	void SetPosition(Vector2 a_vec);

	std::string GetTag();
	void SetTag(std::string a_tag);

protected:
	Transform transform;
	std::string tag;
	float radius;
	aie::Texture* texture;


};


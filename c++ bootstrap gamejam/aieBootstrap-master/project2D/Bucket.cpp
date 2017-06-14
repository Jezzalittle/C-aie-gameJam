#include "Bucket.h"
#include "GameManager.h"


Bucket::Bucket(std::string textureName, Vector2 pos, std::string a_tag) : GameObject()
{
	tag = a_tag;
	transform.SetPosition(pos);
	texture = GameManager::instance().tm->FindByFileName(textureName);
	dragging = false;
	radius = texture->getWidth() / 2.0f;
}

Bucket::Bucket(std::string textureName , Vector2 pos) : GameObject()
{
	tag = "Bucket";
	transform.SetPosition(pos);
	texture = GameManager::instance().tm->FindByFileName(textureName);
	dragging = false;
	radius = texture->getWidth() / 2.0f;
}

Bucket::~Bucket()
{
}

void Bucket::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();



	if (input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT) == true)
	{

		std::cout << input->getMouseX() << " , " << input->getMouseY() << std::endl;
		std::cout << transform.GetPosition().x - (texture->getWidth() / 2) << " , " << transform.GetPosition().y - (texture->getHeight() / 2) << std::endl;
		std::cout << transform.GetPosition().x + (texture->getWidth() / 2) << " , " << transform.GetPosition().y + (texture->getHeight() / 2) << std::endl;
		std::cout << std::endl;

		if (dragging == true)
		{
			dragging = false;
			return;
		}
		if (input->getMouseX() > transform.GetPosition().x  - (texture->getWidth() / 2) && input->getMouseX() < transform.GetPosition().x + (texture->getWidth() / 2) && input->getMouseY() < transform.GetPosition().y + (texture->getHeight() / 2)  && input->getMouseY() > transform.GetPosition().y - (texture->getHeight() / 2))
		{
			dragging = true;
		}
	}
	
	if (dragging == true)
	{
		transform.SetPosition(Vector2((float)input->getMouseX(), (float)input->getMouseY()));
	}
}

void Bucket::Draw(aie::Renderer2D * renderer)
{
	renderer->drawSpriteTransformed3x3(texture, (float*)transform.GetLocalMatrix());
}


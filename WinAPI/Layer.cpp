#include "Layer.h"

namespace ks
{
	Layer::Layer()
	{

	}

	Layer::~Layer()
	{
		for (GameObject* gameObject : gameObjects)
		{
			delete gameObject;
		}
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObject : gameObjects)
		{
			if (gameObject == nullptr)
				continue;

			gameObject->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObject : gameObjects)
		{
			if (gameObject == nullptr
				|| gameObject->GetState() != GameObject::e_State::Active)
				continue;

			gameObject->Update();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObject : gameObjects)
		{
			if (gameObject == nullptr
				|| gameObject->GetState() != GameObject::e_State::Active)
				continue;

			gameObject->Render(hdc);
		}
	}

	void Layer::Release()
	{
		for (GameObject* gameObject : gameObjects)
		{
			if (gameObject == nullptr)
				continue;

			gameObject->Release();
		}
	}

	void Layer::AddGameObject(GameObject* newObject)
	{
		if (newObject == nullptr)
		{
			return;
		}

		gameObjects.push_back(newObject);
	}
}
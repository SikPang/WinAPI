#pragma once

#include <vector>
#include "Entity.h"
#include "GameObject.h"

namespace ks
{
	class Layer : public Entity
	{
	private:
		std::vector<GameObject*> gameObjects;

	public:
		Layer();
		virtual ~Layer();

	public:
		virtual void	Initialize();
		virtual void	Update();
		virtual void	Render(HDC hdc);
		virtual void	Release();
		void AddGameObject(GameObject* newObject);
	};
}
#pragma once

#include <vector>
#include "Entity.h"
#include "GameObject.h"

namespace ks
{
	class Scene : public Entity
	{
	private:
		std::vector<GameObject*> gameObjects;

	public:
		Scene();
		~Scene();
	};
}
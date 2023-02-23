#pragma once

#include <vector>
#include "Entity.h"
#include "Layer.h"

namespace ks
{
	class Scene : public Entity
	{
	private:
		std::vector<Layer> layers;

	public:
		Scene();
		virtual ~Scene();

	public:
		virtual void	Initialize();
		virtual void	Update();
		virtual void	Render(HDC hdc);
		virtual void	Release();
		void AddGameObject(GameObject* newObject, e_LayerType layer);
	};
}
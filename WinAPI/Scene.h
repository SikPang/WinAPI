#pragma once

#include <vector>
#include "Entity.h"
#include "Layer.h"
#include "Image.h"

namespace ks
{
	class Scene : public Entity
	{
	protected:
		Image* bGImage;
		std::vector<Layer> layers;

	public:
		Scene();
		virtual ~Scene();

	public:
		virtual void	Initialize();
		virtual void	Update();
		virtual void	Render(HDC hdc);
		virtual void	Release();
		virtual void	Destroy();

	public:
		void			AddGameObject(GameObject* newObject, e_LayerType layer);
		std::vector<GameObject*>& GetGameObjects(e_LayerType layer);
		virtual void	OnEnter();
		virtual void	OnExit();
	};
}
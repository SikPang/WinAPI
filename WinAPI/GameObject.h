#pragma once

#include <vector>
#include <Windows.h>
#include "Entity.h"
#include "ks_Math.h"
#include "Component.h"

namespace ks
{
	class GameObject : public Entity
	{
	private:
		Vector2	pos;
		HDC		hdc;
		std::vector<Component*>	components;

	public:
		GameObject();
		virtual ~GameObject();

	public:
		virtual void	Initialize();
		virtual void	Update();
		virtual void	Render(HDC hdc);
		virtual void	Release();
		void	SetPos(Vector2 pos) { this->pos = pos; };
	};
}
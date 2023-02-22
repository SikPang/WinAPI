#pragma once

#include <vector>
#include <Windows.h>
#include "Entity.h"
#include "ks_Math.h"
#include "Component.h"

namespace
{
	class GameObject : public Entity
	{
	private:
		Vector2	pos;
		HDC		hdc;
		std::vector<Component*>	components;

	public:
		GameObject();
		~GameObject();
	};
}
#pragma once

#include "Entity.h"

namespace ks
{
	class Component : public Entity
	{

	public:
		void	Initialize();
		void	Update();
		void	Render(HDC hdc);
		void	Release();
	};
}

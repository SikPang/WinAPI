#pragma once

#include "Entity.h"

namespace ks
{
	class Component : public Entity
	{
	private:
		const e_ComponentType	type;

	public:
		Component(e_ComponentType type);
		~Component();

	public:
		virtual void	Initialize();
		virtual void	Update();
		virtual void	Render(HDC hdc);
		virtual void	Release();

	public:
		e_ComponentType	GetType(){ return type; };
	};
}

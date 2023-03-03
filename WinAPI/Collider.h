#pragma once

#include "Component.h"
#include "ks_Math.h"
#include "Enums.h"
#include "Transform.h"

namespace ks
{
	class Collider : public Component
	{
	private:
		Vector2	center;
		Vector2 size;
		Vector2	scale;
		Vector2	pos;

	public:
		Collider();
		~Collider();
	
	public:
		void	Initialize() override;
		void	Update() override;
		void	Render(HDC hdc) override;
		void	Release() override;
		void	SetCenter(Vector2 center) { this->center = center; }
		void	SetSize(Vector2 size) { this->size = size; }
		void	SetScale(Vector2 scale) { this->scale = scale; }
	};
}

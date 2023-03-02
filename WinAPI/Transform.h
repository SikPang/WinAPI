#pragma once
#include "Component.h"
#include "ks_Math.h"

namespace ks
{
	class Transform : public Component
	{
	private:
		Vector2	pos;
		Vector2	scale;

	public:
		Transform();
		~Transform();

	public:
		void	Initialize() override;
		void	Update() override;
		void	Render(HDC hdc) override;
		void	Release() override;

	public:
		void	SetPos(Vector2 pos) { this->pos = pos; };
		void	SetScale(Vector2 scale) { this->scale = scale; };
		Vector2	GetPos() { return pos; };
		Vector2	GetScale() { return scale; };
	};
}
#pragma once
#include "Component.h"
#include "ks_Math.h"

namespace ks
{
	class Transform : public Component
	{
	private:
		Vector2	pos;
		Vector2	size;

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
		void	SetSize(Vector2 size) { this->size = size; };
		Vector2	GetPos() { return pos; };
		Vector2	GetSize() { return size; };
	};
}
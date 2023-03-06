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
		Vector2	pos;

	public:
		Collider();
		~Collider();
	
	public:
		void	Initialize() override;
		void	Update() override;
		void	Render(HDC hdc) override;
		void	Release() override;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

	public:
		void	SetCenter(Vector2 center) { this->center = center; }
		void	SetSize(Vector2 size) { this->size = size; }
		Vector2	GetPos() { return pos; }
		Vector2	GetSize() { return size; }
	};
}

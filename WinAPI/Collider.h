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
		static UINT colliderNumber;
		UINT	id;
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

		void OnCollisionEnter(Collider* other);
		void OnCollisionStay(Collider* other);
		void OnCollisionExit(Collider* other);

	public:
		void	SetCenter(Vector2 center) { this->center = center; }
		void	SetSize(Vector2 size) { this->size = size; }
		Vector2	GetPos() { return pos; }
		Vector2	GetSize() { return size; }
		UINT	GetID() { return id; }
	};
}

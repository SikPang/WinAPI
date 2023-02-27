#pragma once

#include "Entity.h"

namespace ks
{
	// 전방 선언, 헤더 상호 참조 방지
	class GameObject;

	class Component : public Entity
	{
	private:
		GameObject* owner;
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
		void SetGameObject(GameObject* owner) { this->owner = owner; }
		GameObject* GetGameObject() { return owner; }
	};
}

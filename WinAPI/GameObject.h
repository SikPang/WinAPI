#pragma once

#include <vector>
#include <Windows.h>
#include "Entity.h"
#include "ks_Math.h"
#include "Component.h"
#include "Transform.h"

namespace ks
{
	class GameObject : public Entity
	{
	protected:
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

	public:
		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

	public:
		template <typename T>
		T* AddComponent()
		{
			T*		comp = new T();

			components[(UINT)comp->GetType()] = comp;
			comp->SetGameObject(this);
			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			for (Component* component : components)
			{
				T* castedComp = dynamic_cast<T*>(component);

				if (castedComp != nullptr)
					return castedComp;
			}

			return nullptr;
		}
	};
}
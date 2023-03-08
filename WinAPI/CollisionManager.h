#pragma once

#include "Collider.h"
#include "Enums.h"
#include <map>

namespace ks
{
	union ColliderID
	{
		struct
		{
			UINT32	left;
			UINT32	right;
		};
		UINT64	id;
	};

	class Scene;

	class CollisionManager
	{
	private:
		static WORD matrix[(UINT)e_LayerType::Size];
		static std::map<UINT64, bool> collisionMap;

	public:
		static void Update();
		static void LayerCollision(Scene* scene, e_LayerType left, e_LayerType right);
		static void ColliderCollision(Collider* leftCollider, Collider* rightCollider, e_LayerType left, e_LayerType right);
		static bool Intersect(Collider* left, Collider* right);
		static void SetLayer(e_LayerType left, e_LayerType right, bool value);
		static void Clear();
	};
}

#pragma once

#include "Collider.h"
#include "Enums.h"

namespace ks
{
	class Scene;

	class CollisionManager
	{
	private:
		static WORD matrix[(UINT)e_LayerType::Size];

	public:
		static void Update();
		static void LayerCollision(Scene* scene, e_LayerType left, e_LayerType right);
		static bool Intersect(Collider* left, Collider* right);
		static void SetLayer(e_LayerType left, e_LayerType right, bool value);
		static void Clear();
	};
}

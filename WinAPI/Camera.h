#pragma once

#include "ks_Math.h"

namespace ks
{
	class GameObject;

	class Camera
	{
	private:
		static Vector2 resolution;
		static Vector2 lookPosition;
		static Vector2 distance;
		static GameObject* target;

	public:
		static void Initialize();
		static void Update();
		static void Clear();
		static void SetTarget(GameObject* target) { Camera::target = target; }
		static Vector2 CalculatePos(Vector2 pos) { return pos - distance; }
	};
}

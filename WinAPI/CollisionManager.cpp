#include "CollisionManager.h"
#include "SceneManager.h"

namespace ks
{
	WORD CollisionManager::matrix[(UINT)e_LayerType::Size] = {};

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();

		for (UINT row = 0; row < (UINT)e_LayerType::Size; ++row)
		{
			for (UINT col = 0; col < (UINT)e_LayerType::Size; ++col)
			{
				if (matrix[row] & (1 << col))
					LayerCollision(scene, (e_LayerType)row, (e_LayerType)col);
			}
		}
	}

	void CollisionManager::LayerCollision(Scene* scene, e_LayerType left, e_LayerType right)
	{
		const std::vector<GameObject*>& lefts = scene->GetGameObjects(left);
		const std::vector<GameObject*>& rights = scene->GetGameObjects(right);

		for (auto leftObject : lefts)
		{
			Collider* leftCollider = leftObject->GetComponent<Collider>();
			if (leftCollider == nullptr)
				continue;

			for (auto rightObject : rights)
			{
				Collider* rightCollider = leftObject->GetComponent<Collider>();
				if (rightCollider == nullptr || leftObject == rightObject)
					continue;

				if (Intersect(leftCollider, rightCollider))
				{
					// 충돌 o
					int a = 0;
				}
				else
				{
					// 충돌 x
				}
			}
		}
	}
	
	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Vector2 leftPos = left->GetPos();
		Vector2 rightPos = right->GetPos();

		Vector2 leftSize = left->GetSize();
		Vector2 rightSize = right->GetSize();

		// 두 충돌체 간의 거리가 각 면적의 절반끼리의 합보다 짧다면 충돌 
		if (fabs(leftPos.x - rightPos.x) < (leftSize.x / 2.0f) + (rightSize.x / 2.0f)
			&& fabs(leftPos.y - rightPos.y) < (leftSize.y / 2.0f) + (rightSize.y / 2.0f))
		{
			return true;
		}
		return false;
	}
	
	void CollisionManager::SetLayer(e_LayerType left, e_LayerType right, bool value)
	{
		UINT row = 0;
		UINT col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		if (value == true)
			matrix[row] |= (1 << col);
		else
			matrix[col] &= ~(1 << col);
	}
	
	void CollisionManager::Clear()
	{
	
	}
}
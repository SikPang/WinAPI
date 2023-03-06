#include "CollisionManager.h"
#include "SceneManager.h"

namespace ks
{
	WORD CollisionManager::matrix[(UINT)e_LayerType::Size] = {};
	std::map<UINT64, bool> CollisionManager::collisionMap = {};

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
				Collider* rightCollider = rightObject->GetComponent<Collider>();
				if (rightCollider == nullptr || leftObject == rightObject)
					continue;

				ColliderCollision(leftCollider, rightCollider, left, right);
			}
		}
	}

	void CollisionManager::ColliderCollision(Collider* leftCollider, Collider* rightCollider, e_LayerType left, e_LayerType right)
	{
		Collider2D colliderId = {};
		colliderId.left = (UINT)left;
		colliderId.left = (UINT)right;

		std::map<UINT64, bool>::iterator iter = collisionMap.find(colliderId.id);

		if (iter == collisionMap.end())
		{
			collisionMap.insert(std::make_pair(colliderId.id, false));
			iter = collisionMap.find(colliderId.id);
		}

		if (Intersect(leftCollider, rightCollider))
		{
			if (iter->second == false) // 최초 충돌
			{
				leftCollider->OnCollisionEnter(rightCollider);
				rightCollider->OnCollisionEnter(leftCollider);

				iter->second = true;
			}
			else // 충돌 중
			{
				leftCollider->OnCollisionStay(rightCollider);
				rightCollider->OnCollisionStay(leftCollider);
			}
		}
		else
		{
			if (iter->second == true) // 충돌에서 막 빠져나옴
			{
				leftCollider->OnCollisionExit(rightCollider);
				rightCollider->OnCollisionExit(leftCollider);

				iter->second = false;
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
		UINT row;
		UINT col;

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
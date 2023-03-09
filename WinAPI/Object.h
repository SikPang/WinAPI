#pragma once

#include "GameObject.h"
#include "Time.h"
#include "SceneManager.h"

namespace ks
{
	template <typename T>
	static inline T* Instantiate(e_LayerType type, const std::wstring& name)
	{
		T* gameObject = new T();
		
		gameObject->SetName(name);
		gameObject->Initialize();

		SceneManager::GetActiveScene()->AddGameObject(gameObject, type);

		return gameObject;
	}

	template <typename T>
	static inline T* Instantiate(e_LayerType type, const std::wstring& name, Vector2 pos)
	{
		T* gameObject = new T();

		gameObject->SetName(name);
		gameObject->GameObject::GetComponent<Transform>()->SetPos(pos);
		gameObject->Initialize();

		SceneManager::GetActiveScene()->AddGameObject(gameObject, type);

		return gameObject;
	}

	static void Destroy(GameObject* gameObject)
	{
		gameObject->SetState(GameObject::e_State::Death);
	}
}
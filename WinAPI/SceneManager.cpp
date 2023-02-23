#include "SceneManager.h"
#include "PlayScene.h"
#include "Enums.h"

namespace ks
{
	std::vector<Scene*> SceneManager::scenes = {};

	void SceneManager::Initialize()
	{
		scenes.resize((UINT)e_SceneType::Size);

		scenes[(UINT)e_SceneType::Play] = new PlayScene();
		scenes[(UINT)e_SceneType::Play]->SetName(L"PLAY");

		for (Scene* scene : scenes)
		{
			if (scene == nullptr)
				continue;

			scene->Initialize();
		}
	}

	void SceneManager::Update()
	{
		for (Scene* scene : scenes)
		{
			if (scene == nullptr)
				continue;

			scene->Update();
		}
	}

	void SceneManager::Render(HDC hdc)
	{
		for (Scene* scene : scenes)
		{
			if (scene == nullptr)
				continue;

			scene->Render(hdc);
		}
	}

	void SceneManager::Release()
	{
		for (Scene* scene : scenes)
		{
			if (scene == nullptr)
				continue;

			scene->Release();
		}
	}
}
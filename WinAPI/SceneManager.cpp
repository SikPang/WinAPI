#include "SceneManager.h"
#include "PlayScene.h"
#include "TitleScene.h"
#include "Enums.h"

namespace ks
{
	std::vector<Scene*> SceneManager::scenes = {};
	Scene* SceneManager::activeScene = {};

	void SceneManager::Initialize()
	{
		scenes.resize((UINT)e_SceneType::Size);

		scenes[(UINT)e_SceneType::Title] = new TitleScene();
		scenes[(UINT)e_SceneType::Play] = new PlayScene();

		for (Scene* scene : scenes)
		{
			if (scene == nullptr)
				continue;

			scene->Initialize();
		}

		// 현재 활성화된 씬
		LoadScene(e_SceneType::Title);
	}

	void SceneManager::Update()
	{
		activeScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		activeScene->Render(hdc);
	}

	void SceneManager::Release()
	{
		for (Scene* scene : scenes)
		{
			if (scene == nullptr)
				continue;

			delete scene;
			scene = nullptr;
		}
	}

	void SceneManager::Destroy()
	{
		activeScene->Destroy();
	}

	void SceneManager::LoadScene(e_SceneType type)
	{
		if (activeScene != nullptr)
			activeScene->OnExit();

		activeScene = scenes[(UINT)type];
		activeScene->OnEnter();
	}
}
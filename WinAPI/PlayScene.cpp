#include "PlayScene.h"
#include "Input.h"
#include "SceneManager.h"
#include <iostream>
namespace ks
{
	PlayScene::PlayScene()
	{
		
	}

	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		player = new Player();
		player->SetName(L"Player");
		//player->SetPos(Vector2(0.0f, 0.0f));
		AddGameObject(player, e_LayerType::Player);

		Scene::Initialize();
	}
	
	void PlayScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyState(e_KeyCode::N) == e_KeyState::Down)
		{
			SceneManager::LoadScene(e_SceneType::Title);
		}
	}
	
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	
	void PlayScene::Release()
	{
		Scene::Release();
	}

	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{
		//player->SetPos(Vector2(0.0f, 0.0f));
	}
}
#include "PlayScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "ks_Resources.h"

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
		// 씬에 플레이어 추가
		player = new Player();
		player->SetName(L"Player");
		AddGameObject(player, e_LayerType::Player);

		// 배경
		image = Resources::Load<Image>(L"bgPlayImage", L"..\\Resources\\bg_play.bmp");

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

		BitBlt(hdc, 0, 0, image->GetWitdh(), image->GetHeight(), image->GetHdc(), 0, 0, SRCCOPY);
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
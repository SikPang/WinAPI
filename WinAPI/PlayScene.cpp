#include "PlayScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "ks_Resources.h"
#include "Enemy.h"
#include "CollisionManager.h"

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
		AddGameObject(player, e_LayerType::Player);
		player->SetName(L"Me");

		Enemy* enemy = new Enemy();
		AddGameObject(enemy, e_LayerType::Enemy);
		enemy->SetName(L"Zombie");

		CollisionManager::SetLayer(e_LayerType::Player, e_LayerType::Enemy, true);
		// 배경
		image = Resources::Load<Image>(L"bgPlayImage", L"..\\Resources\\bg_play.bmp");

		Scene::Initialize();
	}
	
	void PlayScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(e_KeyCode::N))
		{
			SceneManager::LoadScene(e_SceneType::Title);
		}
	}
	
	void PlayScene::Render(HDC hdc)
	{
		// 씬의 배경화면
		BitBlt(hdc, 0, 0, image->GetWidth(), image->GetHeight(), image->GetHdc(), 0, 0, SRCCOPY);

		// 씬의 오브젝트
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
#include "PlayScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "ks_Resources.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Object.h"

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
		// 게임이 처음 시작될 때, 모든 씬이 초기화되는 과정에서 각각의 씬이 자신의 게임오브젝트를 갖기 위해
		// 잠깐 activeScene을 자신으로 해두고 Instantiate (현재 activeScene에 AddGameObject)
		Scene::Initialize();

		player = ks::Instantiate<Player>(e_LayerType::Player, L"Me", Vector2(200.f, 300.f));

		ks::Instantiate<Enemy>(e_LayerType::Enemy, L"Enemy1", Vector2(400.f, 300.f));
		ks::Instantiate<Enemy>(e_LayerType::Enemy, L"Enemy2", Vector2(0.f, 300.f));

		// 배경
		bGImage = Resources::Load<Image>(L"bgPlayImage", L"..\\Resources\\bg_play.bmp");

		Camera::SetTarget(player);
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
		BitBlt(hdc, 0, 0, bGImage->GetWidth(), bGImage->GetHeight(), bGImage->GetHdc(), 0, 0, SRCCOPY);

		// 씬의 오브젝트
		Scene::Render(hdc);
	}
	
	void PlayScene::Release()
	{
		Scene::Release();
	}

	void PlayScene::OnEnter()
	{
		CollisionManager::SetLayer(e_LayerType::Player, e_LayerType::Enemy, true);
		Camera::SetTarget(player);
	}

	void PlayScene::OnExit()
	{
		CollisionManager::Clear();
		Camera::Clear();
		//player->SetPos(Vector2(0.0f, 0.0f));
	}
}
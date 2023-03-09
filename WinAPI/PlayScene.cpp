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
		Player* player = ks::Instantiate<Player>(e_LayerType::Player, L"Me", Vector2(200.f, 300.f));

		ks::Instantiate<Enemy>(e_LayerType::Enemy, L"Enemy1", Vector2(400.f, 300.f));
		ks::Instantiate<Enemy>(e_LayerType::Enemy, L"Enemy2", Vector2(0.f, 300.f));

		// ���
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
		// ���� ���ȭ��
		BitBlt(hdc, 0, 0, bGImage->GetWidth(), bGImage->GetHeight(), bGImage->GetHdc(), 0, 0, SRCCOPY);

		// ���� ������Ʈ
		Scene::Render(hdc);
	}
	
	void PlayScene::Release()
	{
		Scene::Release();
	}

	void PlayScene::OnEnter()
	{
		CollisionManager::SetLayer(e_LayerType::Player, e_LayerType::Enemy, true);
	}

	void PlayScene::OnExit()
	{
		CollisionManager::Clear();
		//player->SetPos(Vector2(0.0f, 0.0f));
	}
}
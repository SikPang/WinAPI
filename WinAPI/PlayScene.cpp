#include "PlayScene.h"
#include "Player.h"

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
		Player* player = new Player();
		player->SetName(L"Player");
		//player->SetPos(Vector2(0.0f, 0.0f));
		AddGameObject(player, e_LayerType::Player);

		Scene::Initialize();
	}
	
	void PlayScene::Update()
	{
		Scene::Update();
	}
	
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	
	void PlayScene::Release()
	{
		Scene::Release();
	}
}
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
		Scene::Initialize();

		Player* player = new Player();
		AddGameObject(player, e_LayerType::Player);
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
#include "TitleScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "ks_Resources.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "Object.h"
#include "Player.h"

namespace ks
{
	TitleScene::TitleScene()
	{

	}

	TitleScene::~TitleScene()
	{

	}

	void TitleScene::Initialize()
	{
		// 게임이 처음 시작될 때, 모든 씬이 초기화되는 과정에서 각각의 씬이 자신의 게임오브젝트를 갖기 위해
		// 잠깐 activeScene을 자신으로 해두고 Instantiate (현재 activeScene에 AddGameObject)
		Scene::Initialize();

		// 배경
		bGImage = Resources::Load<Image>(L"bgTitleImage", L"..\\Resources\\bg_title.bmp");
	}

	void TitleScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(e_KeyCode::N))
		{
			SceneManager::LoadScene(e_SceneType::Play);
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		// 씬의 배경 화면
		BitBlt(hdc, 0, 0, bGImage->GetWidth(), bGImage->GetHeight(), bGImage->GetHdc(), 0, 0, SRCCOPY);

		// 씬의 오브젝트
		Scene::Render(hdc);
	}

	void TitleScene::Release()
	{
		Scene::Release();
	}

	void TitleScene::OnEnter()
	{
		
	}

	void TitleScene::OnExit()
	{
		//CollisionManager::Clear();
		//Camera::Clear();
	}
}
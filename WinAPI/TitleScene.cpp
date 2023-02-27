#include "TitleScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "ks_Resources.h"

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
		Scene::Initialize();

		image = Resources::Load<Image>(L"bgPlayImage", L"..\\Resources\\bg_title.bmp");
	}

	void TitleScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyState(e_KeyCode::N) == e_KeyState::Down)
		{
			SceneManager::LoadScene(e_SceneType::Play);
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		BitBlt(hdc, 0, 0, image->GetWitdh(), image->GetHeight(), image->GetHdc(), 0, 0, SRCCOPY);
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

	}
}
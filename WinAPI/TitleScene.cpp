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
		image = Resources::Load<Image>(L"bgTitleImage", L"..\\Resources\\bg_title.bmp");
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
		BitBlt(hdc, 0, 0, image->GetWidth(), image->GetHeight(), image->GetHdc(), 0, 0, SRCCOPY);

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

	}
}
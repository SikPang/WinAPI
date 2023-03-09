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
		// ������ ó�� ���۵� ��, ��� ���� �ʱ�ȭ�Ǵ� �������� ������ ���� �ڽ��� ���ӿ�����Ʈ�� ���� ����
		// ��� activeScene�� �ڽ����� �صΰ� Instantiate (���� activeScene�� AddGameObject)
		Scene::Initialize();

		// ���
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
		// ���� ��� ȭ��
		BitBlt(hdc, 0, 0, bGImage->GetWidth(), bGImage->GetHeight(), bGImage->GetHdc(), 0, 0, SRCCOPY);

		// ���� ������Ʈ
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
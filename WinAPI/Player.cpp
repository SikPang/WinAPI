#include "Player.h"
#include "Time.h"
#include "Input.h"
#include "ks_Resources.h"
#include "Image.h"
#include "Animator.h"

namespace ks
{
	Player::Player()
	{
	
	}
	
	Player::~Player()
	{
	
	}
	
	void Player::Initialize()
	{
		image = Resources::Load<Image>(L"playerImage", L"..\\Resources\\player.bmp");

		Animator* animator = AddComponent<Animator>();
		animator->CreateAnimation(L"GoRight", image, Vector2::Zero, 16, 8, 16, Vector2::Zero, 0.1);
		animator->CreateAnimation(L"Idle", image, Vector2(0.0f, 113.0f * 5), 16, 8, 16, Vector2::Zero, 0.1);
		
		animator->Play(L"Idle", true);

		transform = GetComponent<Transform>();
		if (transform != nullptr)
			transform->SetPos(Vector2(200, 200));

		GameObject::Initialize();
	}
	
	void Player::Update()
	{
		GameObject::Update();

		transform = GetComponent<Transform>();
		if (transform == nullptr)
			return;

		Vector2 pos = transform->GetPos();

		if (Input::GetKeyState(e_KeyCode::A) == e_KeyState::Pressed)
		{
			pos.x -= 200.f * Time::GetDeltaTime();
		}

		if (Input::GetKeyState(e_KeyCode::D) == e_KeyState::Pressed)
		{
			pos.x += 200.f * Time::GetDeltaTime();
		}

		if (Input::GetKeyState(e_KeyCode::W) == e_KeyState::Pressed)
		{
			pos.y -= 200.f * Time::GetDeltaTime();
		}

		if (Input::GetKeyState(e_KeyCode::S) == e_KeyState::Pressed)
		{
			pos.y += 200.f * Time::GetDeltaTime();
		}

		transform->SetPos(pos);
	}
	
	void Player::Render(HDC hdc)
	{
		TransparentBlt(hdc, transform->GetPos().x, transform->GetPos().y, image->GetWitdh(), image->GetHeight(),
			image->GetHdc(), 0, 0, image->GetWitdh(), image->GetHeight(), RGB(255, 0, 255));

		//BitBlt(hdc, transform->GetPos().x, transform->GetPos().y, image->GetWitdh(), image->GetHeight(), image->GetHdc(), 0, 0, SRCCOPY);

		GameObject::Render(hdc);
	}
	
	void Player::Release()
	{
		GameObject::Release();
	}
}
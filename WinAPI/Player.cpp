#include "Player.h"
#include "Time.h"
#include "Input.h"
#include "ks_Resources.h"
#include "Image.h"

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
		GameObject::Initialize();

		image = Resources::Load<Image>(L"playerImage", L"..\\Resources\\player.bmp");

		transform = GetComponent<Transform>();
		if (transform != nullptr)
			transform->SetPos(Vector2(200, 200));
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
		BitBlt(hdc, transform->GetPos().x, transform->GetPos().y, image->GetWitdh(), image->GetHeight(), image->GetHdc(), 0, 0, SRCCOPY);

		GameObject::Render(hdc);
	}
	
	void Player::Release()
	{
		delete image;
		GameObject::Release();
	}
}
#include "Player.h"
#include "Time.h"
#include "Input.h"
#include "Resources.h"
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
		Image* playerImage = Resources::Load<Image>(L"playerImage", L"..\\Resources\\player.bmp");

		GameObject::Initialize();

		pos.x = 200;
		pos.y = 200;
	}
	
	void Player::Update()
	{
		GameObject::Update();

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
	}
	
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		HBRUSH brush = CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH prev = (HBRUSH)SelectObject(hdc, brush);
		Rectangle(hdc, pos.x, pos.y, pos.x + 100, pos.y + 100);
		SelectObject(hdc, prev);
		DeleteObject(brush);
	}
	
	void Player::Release()
	{
		GameObject::Release();
	}
}
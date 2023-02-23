#include "Player.h"
#include "Time.h"

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

		pos.x = 200;
		pos.y = 200;
	}
	
	void Player::Update()
	{
		GameObject::Update();

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			pos.x -= 200.f * Time::GetDeltaTime();
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			pos.x += 200.f * Time::GetDeltaTime();
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			pos.y -= 200.f * Time::GetDeltaTime();
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
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
	}
	
	void Player::Release()
	{
		GameObject::Release();
	}
}
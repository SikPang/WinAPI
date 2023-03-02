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
		image = Resources::Load<Image>(L"playerImage", L"..\\Resources\\Player\\player.bmp");

		animator = AddComponent<Animator>();
		animator->CreateAnimation(L"GoRight", image, Vector2::Zero, 16, 8, 16, Vector2::Zero, 0.1);
		animator->CreateAnimation(L"Idle", image, Vector2(0.0f, 113.0f * 5), 16, 8, 16, Vector2::Zero, 0.1);

		animator->CreateAnimations(L"..\\Resources\\Player", Vector2::Zero, 0.1f);

		animator->Play(L"Idle", true);

		transform = GetComponent<Transform>();

		state = e_PlayerState::Idle;
		
		GameObject::Initialize();
	}
	
	void Player::Update()
	{
		GameObject::Update();

		switch (state)
		{
		case e_PlayerState::Move:
			Move();
			break;
		case e_PlayerState::Attack:
			Attack();
			break;
		case e_PlayerState::Death:
			Death();
			break;
		case e_PlayerState::Idle:
			Idle();
			break;
		default:
			break;
		}
	}
	
	void Player::Render(HDC hdc)
	{
		TransparentBlt(hdc, transform->GetPos().x, transform->GetPos().y, image->GetWidth(), image->GetHeight(),
			image->GetHdc(), 0, 0, image->GetWidth(), image->GetHeight(), RGB(255, 0, 255));

		//BitBlt(hdc, transform->GetPos().x, transform->GetPos().y, image->GetWidth(), image->GetHeight(), image->GetHdc(), 0, 0, SRCCOPY);

		GameObject::Render(hdc);
	}
	
	void Player::Release()
	{
		GameObject::Release();
	}

	void Player::Move()
	{
		if (Input::GetKeyUp(e_KeyCode::A)
			|| Input::GetKeyUp(e_KeyCode::D)
			|| Input::GetKeyUp(e_KeyCode::W)
			|| Input::GetKeyUp(e_KeyCode::S))
		{
			state = e_PlayerState::Move;
		}

		animator->Play(L"GoRight", true);

		Vector2 pos = transform->GetPos();

		if (Input::GetKey(e_KeyCode::A))
		{
			pos.x -= 200.f * Time::GetDeltaTime();
		}

		if (Input::GetKey(e_KeyCode::D))
		{
			pos.x += 200.f * Time::GetDeltaTime();
		}

		if (Input::GetKey(e_KeyCode::W))
		{
			pos.y -= 200.f * Time::GetDeltaTime();
		}

		if (Input::GetKey(e_KeyCode::S))
		{
			pos.y += 200.f * Time::GetDeltaTime();
		}

		transform->SetPos(pos);
	}
	
	void Player::Attack()
	{
	
	}
	
	void Player::Death()
	{
	
	}
	
	void Player::Idle()
	{
		if (Input::GetKeyDown(e_KeyCode::A)
			|| Input::GetKeyDown(e_KeyCode::D)
			|| Input::GetKeyDown(e_KeyCode::W)
			|| Input::GetKeyDown(e_KeyCode::S))
		{
			state = e_PlayerState::Move;
			animator->Play(L"Idle", true);
		}
	}
}
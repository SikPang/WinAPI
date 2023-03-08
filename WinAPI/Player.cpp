#include "Player.h"
#include "Time.h"
#include "Input.h"
#include "ks_Resources.h"
#include "Image.h"
#include "Collider.h"
#include "Bullet.h"
#include "SceneManager.h"
#include "Enums.h"

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
		image = Resources::Load<Image>(L"playerImage", L"..\\Resources\\SpriteSheet\\Player\\player.bmp");

		animator = AddComponent<Animator>();
		//animator->CreateAnimation(L"GoRight", image, Vector2::Zero, 16, 8, 16, Vector2::Zero, 0.1);
		animator->CreateAnimation(L"Idle", image, Vector2::Zero, 3, 1, 3, Vector2::Zero, 0.1f);

		animator->GetStartEvent(L"Idle") = std::bind(&Player::idleCompleteEvent, this);

		animator->Play(L"Idle", true);

		//animator->CreateAnimations(L"..\\Resources\\Sprites\\Player", Vector2::Zero, 0.1f);
		//animator->Play(L"ResourcesPlayer", true);

		transform = GetComponent<Transform>();

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-60.f, -80.f));

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
		//TransparentBlt(hdc, transform->GetPos().x, transform->GetPos().y, image->GetWidth(), image->GetHeight(),
		//	image->GetHdc(), 0, 0, image->GetWidth(), image->GetHeight(), RGB(255, 0, 255));

		//BitBlt(hdc, transform->GetPos().x, transform->GetPos().y, image->GetWidth(), image->GetHeight(), image->GetHdc(), 0, 0, SRCCOPY);

		GameObject::Render(hdc);
	}
	
	void Player::Release()
	{
		GameObject::Release();
	}

	void Player::OnCollisionEnter(Collider* other)
	{
		
	}

	void Player::OnCollisionStay(Collider* other)
	{

	}

	void Player::OnCollisionExit(Collider* other)
	{

	}

	void Player::Move()
	{
		if (Input::GetKeyUp(e_KeyCode::A)
			|| Input::GetKeyUp(e_KeyCode::D)
			|| Input::GetKeyUp(e_KeyCode::W)
			|| Input::GetKeyUp(e_KeyCode::S))
		{
			state = e_PlayerState::Idle;
		}

		//animator->Play(L"GoRight", true);

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
		if (Input::GetKey(e_KeyCode::K))
		{
			Bullet* newBullet = new Bullet();
			newBullet->GetComponent<Transform>()->SetPos(transform->GetPos());
			SceneManager::GetActiveScene()->AddGameObject(newBullet, e_LayerType::Bullet);
		}

		if (Input::GetKeyUp(e_KeyCode::K))
		{
			state = e_PlayerState::Idle;
			animator->Play(L"Idle", true);
		}
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

		if (Input::GetKeyDown(e_KeyCode::K))
		{
			state = e_PlayerState::Attack;
			animator->Play(L"Idle", true);
		}
	}

	void Player::idleCompleteEvent()
	{
		//Bullet* newBullet = new Bullet();
		//newBullet->GetComponent<Transform>()->SetPos(transform->GetPos());
		//SceneManager::GetActiveScene()->AddGameObject(newBullet, e_LayerType::Bullet);
	}
}
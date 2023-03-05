#include "Enemy.h"
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
	Enemy::Enemy()
	{
	
	}
	
	Enemy::~Enemy()
	{
	
	}
	
	void Enemy::Initialize()
	{
		image = Resources::Load<Image>(L"EnemyImage", L"..\\Resources\\Enemy\\enemy.bmp");

		animator = AddComponent<Animator>();
		animator->CreateAnimation(L"GoRight", image, Vector2::Zero, 16, 8, 16, Vector2::Zero, 0.1);
		animator->CreateAnimation(L"Idle", image, Vector2(0.0f, 113.0f * 5), 16, 8, 16, Vector2::Zero, 0.1);

		animator->Play(L"Idle", true);

		//animator->CreateAnimations(L"..\\Resources\\Enemy", Vector2::Zero, 0.1f);
		//animator->Play(L"ResourcesEnemy", true);

		transform = GetComponent<Transform>();
		transform->SetPos(Vector2(300.0f, 200.0f));
		transform->SetScale(Vector2(1.5f, 1.5f));

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-60.f, -80.f));

		state = e_EnemyState::Idle;
		
		GameObject::Initialize();
	}
	
	void Enemy::Update()
	{
		GameObject::Update();

		switch (state)
		{
		case e_EnemyState::Move:
			Move();
			break;
		case e_EnemyState::Attack:
			Attack();
			break;
		case e_EnemyState::Death:
			Death();
			break;
		case e_EnemyState::Idle:
			Idle();
			break;
		default:
			break;
		}
	}
	
	void Enemy::Render(HDC hdc)
	{
		//TransparentBlt(hdc, transform->GetPos().x, transform->GetPos().y, image->GetWidth(), image->GetHeight(),
		//	image->GetHdc(), 0, 0, image->GetWidth(), image->GetHeight(), RGB(255, 0, 255));

		//BitBlt(hdc, transform->GetPos().x, transform->GetPos().y, image->GetWidth(), image->GetHeight(), image->GetHdc(), 0, 0, SRCCOPY);

		GameObject::Render(hdc);
	}
	
	void Enemy::Release()
	{
		GameObject::Release();
	}

	void Enemy::Move()
	{

	}
	
	void Enemy::Attack()
	{

	}
	
	void Enemy::Death()
	{
	
	}
	
	void Enemy::Idle()
	{
		
	}
}
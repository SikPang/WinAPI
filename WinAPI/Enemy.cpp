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
		transform = GetComponent<Transform>();
		transform->SetScale(Vector2(0.55f, 0.55f));

		image = Resources::Load<Image>(L"EnemyImage", L"..\\Resources\\SpriteSheet\\Enemy\\enemy.bmp");

		animator = AddComponent<Animator>();
		//animator->CreateAnimation(L"GoRight", image, Vector2::Zero, 16, 8, 16, Vector2::Zero, 0.1);
		animator->CreateAnimation(L"Idle", image, Vector2::Zero, 3, 1, 3, Vector2::Zero, 0.1);

		animator->Play(L"Idle", true);

		//animator->CreateAnimations(L"..\\Resources\\Sprites\\Enemy", Vector2::Zero, 0.1f);
		//animator->Play(L"ResourcesEnemy", true);


		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-(int)image->GetWidth()/7, -(int)image->GetHeight()));	// width ¼öÁ¤
		collider->SetSize(Vector2((int)(image->GetWidth() / 3 * transform->GetScale().x)
			, (int)(image->GetHeight() * transform->GetScale().y)));

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
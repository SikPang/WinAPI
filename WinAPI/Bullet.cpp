#include "Bullet.h"
#include "Transform.h"
#include "Time.h"
#include "Object.h"

namespace ks
{
	Bullet::Bullet()
		: time(0.f)
	{

	}

	Bullet::~Bullet()
	{
	
	}
	
	void Bullet::Initialize()
	{
	
	}
	
	void Bullet::Update()
	{
		Transform* transform = GetComponent<Transform>();

		Vector2 dir = Vector2(500.f, 200.f);
		dir.Normalize();

		Vector2 pos = transform->GetPos();
		pos.x += 300.f * dir.x * Time::GetDeltaTime();
		pos.y += 300.f * dir.y * Time::GetDeltaTime();
		
		transform->SetPos(pos);

		time += Time::GetDeltaTime();
		if (time > 2.0f)
			ks::Destroy(this);
	}
	
	void Bullet::Render(HDC hdc)
	{
		Transform* transform = GetComponent<Transform>();
		Vector2 pos = transform->GetPos();

		HPEN pen = CreatePen(BS_SOLID, 2, RGB(255, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);

		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Ellipse(hdc, pos.x, pos.y, pos.x + 50.f, pos.y + 50.f);

		SelectObject(hdc, oldPen);
		SelectObject(hdc, oldBrush);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	
	void Bullet::Release()
	{
	
	}
}
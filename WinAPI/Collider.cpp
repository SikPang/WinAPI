#include "Collider.h"
#include "GameObject.h"

namespace ks
{
	Collider::Collider()
		: Component(e_ComponentType::Collider)
		, center(Vector2::Zero)
		, pos(Vector2::Zero)
		, size(100.f, 100.f)
	{

	}

	Collider::~Collider()
	{
	
	}
	
	void Collider::Initialize()
	{
		
	}
	
	void Collider::Update()
	{
		Transform* transform = GetGameObject()->GetComponent<Transform>();
		pos = transform->GetPos() + center;
	}
	
	void Collider::Render(HDC hdc)
	{
		HPEN pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);

		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, pos.x, pos.y, pos.x + size.x, pos.y + size.y);

		SelectObject(hdc, oldPen);
		SelectObject(hdc, oldBrush);
		DeleteObject(pen);
		DeleteObject(brush);
	}
	
	void Collider::Release()
	{
	
	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		
	}
	
	void Collider::OnCollisionStay(Collider* other)
	{
		
	}
	
	void Collider::OnCollisionExit(Collider* other)
	{
		
	}
}
#include "Transform.h"

namespace ks
{
	Transform::Transform()
		: Component(e_ComponentType::Transform)
		, pos(Vector2::Zero)
		, scale(Vector2::One)
	{

	}

	Transform::~Transform()
	{

	}

	void Transform::Initialize()
	{

	}

	void Transform::Update()
	{

	}

	void Transform::Render(HDC hdc)
	{

	}

	void Transform::Release()
	{

	}
}
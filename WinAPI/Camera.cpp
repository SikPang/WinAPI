#include "Camera.h"
#include "Application.h"
#include "GameObject.h"
#include "Transform.h"

extern ks::Application application;

namespace ks
{
	Vector2 Camera::resolution = Vector2::Zero;
	Vector2 Camera::lookPosition = Vector2::Zero;
	Vector2 Camera::distance = Vector2::Zero;
	GameObject* Camera::target = nullptr;

	void Camera::Initialize()
	{
		resolution = application.GetResolution();
		lookPosition = resolution / 2.f;
	}

	void Camera::Update()
	{
		if (target != nullptr)
			lookPosition = target->GetComponent<Transform>()->GetPos();

		distance = lookPosition - resolution / 2.f;
	}

	void Camera::Clear()
	{
		Initialize();
		distance = Vector2::Zero;
	}
}
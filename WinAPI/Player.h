#pragma once

#include "GameObject.h"
#include "Image.h"
#include "Transform.h"
#include "Animator.h"

namespace ks
{
	class Player : public GameObject
	{
	public:
		enum class e_PlayerState
		{
			Move,
			Attack,
			Death,
			Idle
		};

	private:
		Image*		image;
		Transform*	transform;
		Animator*	animator;
		e_PlayerState state;

	private:
		void	Move();
		void	Attack();
		void	Death();
		void	Idle();

	public:
		Player();
		virtual ~Player();

	public:
		void	Initialize() override;
		void	Update() override;
		void	Render(HDC hdc) override;
		void	Release() override;
	};
}

#pragma comment(lib, "Msimg32.lib")
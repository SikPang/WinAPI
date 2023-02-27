#pragma once

#include "GameObject.h"
#include "Image.h"
#include "Transform.h"

namespace ks
{
	class Player : public GameObject
	{
	protected:
		Image*		image;
		Transform*	transform;

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
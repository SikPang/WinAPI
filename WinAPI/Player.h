#pragma once

#include "GameObject.h"

namespace ks
{
	class Player : public GameObject
	{
	private:
		Vector2 pos;

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

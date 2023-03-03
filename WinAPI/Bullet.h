#pragma once
#include "GameObject.h"

namespace ks
{
    class Bullet : public GameObject
    {
    private:


	public:
		Bullet();
		virtual ~Bullet();

	public:
		void	Initialize() override;
		void	Update() override;
		void	Render(HDC hdc) override;
		void	Release() override;
    };
}

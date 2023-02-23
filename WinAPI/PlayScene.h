#pragma once
#include "Scene.h"

namespace ks
{
	class PlayScene : public Scene
	{
	private:

	public:
		PlayScene();
		~PlayScene();

	public:
		void	Initialize() override;
		void	Update() override;
		void	Render(HDC hdc) override;
		void	Release() override;
	};
}

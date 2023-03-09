#pragma once
#include "Scene.h"
#include "Player.h"

namespace ks
{
	class PlayScene : public Scene
	{
	private:
		Player* player;

	public:
		PlayScene();
		~PlayScene();

	public:
		void	Initialize() override;
		void	Update() override;
		void	Render(HDC hdc) override;
		void	Release() override;
		void	OnEnter() override;
		void	OnExit() override;
	};
}

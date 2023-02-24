#pragma once
#include "Scene.h"

namespace ks
{
	class TitleScene : public Scene
	{
	private:

	public:
		TitleScene();
		~TitleScene();

	public:
		void	Initialize() override;
		void	Update() override;
		void	Render(HDC hdc) override;
		void	Release() override;
		void	OnEnter() override;
		void	OnExit() override;
	};
}

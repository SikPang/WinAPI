#pragma once

#include <vector>
#include "Scene.h"

namespace ks
{
	class SceneManager
	{
	private:
		static std::vector<Scene*> scenes;
		static Scene* activeScene; // 현재 활성화된 씬

	public:
		static void	Initialize();
		static void	Update();
		static void	Render(HDC hdc);
		static void	Release();
		static void	LoadScene(e_SceneType type);
	};
}

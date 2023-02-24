#pragma once

#include <vector>
#include "Scene.h"

namespace ks
{
	class SceneManager
	{
	private:
		static std::vector<Scene*> scenes;
		static Scene* activeScene; // ���� Ȱ��ȭ�� ��

	public:
		static void	Initialize();
		static void	Update();
		static void	Render(HDC hdc);
		static void	Release();
		static void	LoadScene(e_SceneType type);
	};
}

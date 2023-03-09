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
		static void	Destroy();

	public:
		static void	LoadScene(e_SceneType type);
		static Scene* GetActiveScene() { return activeScene; }
		static void	SetActiveScene(Scene* scene) { activeScene = scene; }
	};
}

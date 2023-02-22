#pragma once

#include <windows.h>
#include "ks_Math.h"

namespace ks
{
	class Application
	{
	private:
		HWND	hwnd;
		HDC		hdc;
		Vector2	pos;

	public:
		Application();
		~Application();

		void	Initialize(HWND hwnd);
		void	Run();
		void	Update();
		void	Render();
		void	Release();
	};
}
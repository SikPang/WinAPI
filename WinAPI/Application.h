#pragma once

#include <windows.h>
#include "ks_Math.h"

namespace ks
{
	class Application
	{
	private:
		HWND	hwnd;
		HBITMAP	backBuffer;
		HDC		hdc;
		HDC		backHdc;
		Vector2	pos;
		UINT	width;
		UINT	height;

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
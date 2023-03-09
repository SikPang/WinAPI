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

		void	clear();

	public:
		Application();
		~Application();
	
	public:
		void	Initialize(HWND hwnd);
		void	Run();
		void	Update();
		void	Render();
		HWND	GetHwnd() { return hwnd; }
		HDC		GetHdc() { return hdc; }
		Vector2	GetResolution() { return Vector2((int)width, (int)height); }
	};
}

extern ks::Application application;
#include "ks_Application.h"

namespace ks
{
	Application::Application()
		: hwnd(NULL)
		, hdc(NULL)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		this->hwnd = hwnd;
		hdc = GetDC(hwnd);
		pos.x = 200;
		pos.y = 200;
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			pos.x -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			pos.x += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			pos.y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			pos.y += 0.01f;
		}
	}

	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH prev = (HBRUSH)SelectObject(hdc, brush);
		Rectangle(hdc, pos.x, pos.y, pos.x + 100, pos.y + 100);
	}

	void Application::Release()
	{

	}
}
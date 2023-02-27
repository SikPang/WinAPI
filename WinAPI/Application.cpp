#include "Application.h"
#include "SceneManager.h"
#include "Time.h"
#include "Input.h"

namespace ks
{
	Application::Application()
		: hwnd(NULL)
		, hdc(NULL)
	{

	}

	Application::~Application()
	{
		Time::Release();
		SceneManager::Release();
	}

	void Application::clear()
	{
		HBRUSH gray = CreateSolidBrush(RGB(121, 121, 121));
		HBRUSH old = (HBRUSH)SelectObject(backHdc, gray);
		Rectangle(backHdc, -1, -1, 1602, 902);
		SelectObject(backHdc, old);
		DeleteObject(gray);
	}

	void Application::Initialize(HWND hwnd)
	{
		this->hwnd = hwnd;
		hdc = GetDC(hwnd);
		width = 1600;
		height = 900;

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(hwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(hwnd, true);

		backBuffer = CreateCompatibleBitmap(hdc, width, height);
		backHdc = CreateCompatibleDC(hdc);
		HBITMAP prevBitmap = (HBITMAP)SelectObject(backHdc, backBuffer);
		DeleteObject(prevBitmap);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		SceneManager::Update();
	}

	void Application::Render()
	{
		clear();

		Time::Render(backHdc);
		Input::Render(backHdc);
		SceneManager::Render(backHdc);

		// 백버퍼의 그림을 원본에 그려줌
		BitBlt(hdc, 0, 0, width, height, backHdc, 0, 0, SRCCOPY);
	}
}
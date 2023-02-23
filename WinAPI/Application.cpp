#include "Application.h"
#include "SceneManager.h"
#include "Time.h"

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
		
		Time::Initialize();
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
		SceneManager::Update();
	}

	void Application::Render()
	{
		Time::Render(hdc);
		SceneManager::Render(hdc);
	}

	void Application::Release()
	{
		Time::Release();
		SceneManager::Release();
	}
}
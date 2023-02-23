#pragma once

#include <Windows.h>

namespace ks
{
	class Time
	{
	private:
		static double deltaTime;
		static LARGE_INTEGER cpuFrequency;
		static LARGE_INTEGER prevFrequency;
		static LARGE_INTEGER curFrequency;

	public:
		static void	Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release();
		__forceinline static double GetDeltaTime() { return deltaTime; };
	};
}

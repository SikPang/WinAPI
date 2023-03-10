#pragma once

#include <vector>
#include <Windows.h>

namespace ks
{
	enum class e_KeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		END
	};

	enum class e_KeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	class Input
	{
	public:
		struct Key
		{
			e_KeyCode keyCode;
			e_KeyState keyState;
			bool isPressed;
		};

	private:
		static std::vector<Key> keys;

	public:
		static void	Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release();

		static __forceinline bool GetKey(e_KeyCode keyCode)
		{
			return keys[(UINT)keyCode].keyState == e_KeyState::Pressed;
		}

		static __forceinline bool GetKeyDown(e_KeyCode keyCode)
		{
			return keys[(UINT)keyCode].keyState == e_KeyState::Down;
		}

		static __forceinline bool GetKeyUp(e_KeyCode keyCode)
		{
			return keys[(UINT)keyCode].keyState == e_KeyState::Up;
		}
	};
}
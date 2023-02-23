#include "Input.h"

namespace ks
{
	int ASCII[(UINT)e_KeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M'
	};

	std::vector<Input::Key> Input::keys = {};

	void Input::Initialize()
	{
		for (UINT i = 0; i < (UINT)e_KeyCode::END; ++i)
		{
			Key keyInfo;
			keyInfo.keyCode = (e_KeyCode)i;
			keyInfo.keyState = e_KeyState::None;
			keyInfo.isPressed = false;

			keys.push_back(keyInfo);
		}
	}

	void Input::Update()
	{
		for (UINT i = 0; i < (UINT)e_KeyCode::END; ++i)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) // 해당 키 눌림
			{
				// 이전 프레임에도 눌려있었다면
				if (keys[i].isPressed)
					keys[i].keyState = e_KeyState::Pressed;
				else
					keys[i].keyState = e_KeyState::Down;

				keys[i].isPressed = true;
			}
			else //해당 키 안 눌림
			{
				// 이전 프레임에 눌려있었다면
				if (keys[i].isPressed)
					keys[i].keyState = e_KeyState::Up;
				else
					keys[i].keyState = e_KeyState::None;

				keys[i].isPressed = false;
			}
		}
	}

	void Input::Render(HDC hdc)
	{

	}

	void Input::Release()
	{

	}
}
#include "rongInput.h"
namespace rong
{
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	};
	//변수의 흐름 주목 키보드각 키에 대응하는 변수를 벡터로 만들어서 저장.
	//이니셜라이즈 함수에서 실제 키보드의 상태를 판별할 객체 생성.
	//이후 밑의 여러가지 함수들에 들어갈 매개변수(인자)는 모두 실제 생성된 객체의 주소를 참조한다.
	void rong::Input::Initialize()
	{
		createKeys();
	}

	void rong::Input::Update()
	{
		for (size_t i = 0; i < Keys.size(); i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (Keys[i].bPressed == true)
				Keys[i].state = eKeyState::Pressed;
				else
				Keys[i].state = eKeyState::Down;
				
				Keys[i].bPressed = true;
			}
			else
			{
				if (Keys[i].bPressed == true)
					Keys[i].state = eKeyState::Up;
				else
					Keys[i].state = eKeyState::None;

				Keys[i].bPressed = false;
			}
		}
	}
	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keycode = (eKeyCode)i;

			Keys.emplace_back(key);
		}
	}
	void Input::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
		{
			updateKey(key);
		});
	}

	void Input::updateKey(Input::Key& key)
	{
		if (isKeyDown(key.keycode))
			updateKeyDown(key);
		else
			updateKeyUp(key);
	}

	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}
	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;

		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;

		key.bPressed = false;
	}
	
}

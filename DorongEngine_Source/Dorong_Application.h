#pragma once
#include "CommonInclude.h"
#include "rongGameObject.h"

namespace rong
{
	class Application
	{
	public:
		Application():mHwnd(nullptr),mHdc(nullptr)
		{}
		~Application() {};
		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();
	
	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mPlayer;
		

	};
}

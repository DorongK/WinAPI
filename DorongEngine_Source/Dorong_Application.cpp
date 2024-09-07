#include "Dorong_Application.h"
#include "rongInput.h"
#include "rongTime.h"

namespace rong
{
	Application::Application()
		:mHwnd(nullptr), mHdc(nullptr),mHeight(0),mWidth(0),mBackHdc(NULL),mBackBitmap(NULL)
	{
	}
	void Application::Initialize(HWND hwnd , UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0 ,0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd,nullptr,0,0,mWidth,mHeight,0);

		ShowWindow(mHwnd, true);
		//윈도우 해상도에 맞는 백버퍼
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		//백버퍼를 가리킬 dc생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitMap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitMap);

		mPlayer.SetPosition(0.0f, 0.0f);
		Input::Initialize();
		Time::Initialize();

	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
		mPlayer2.Update();
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);
		mPlayer2.Render(mHdc);

		//원본dc,BackBuffer에 있는걸 (그려질 소스) 원본 Buffet(원본 dc)에 그리겠다는 뜻.
		BitBlt(mHdc, 0, 0, mWidth, mHeight
			, mBackHdc, 0, 0, SRCCOPY);
	}
}
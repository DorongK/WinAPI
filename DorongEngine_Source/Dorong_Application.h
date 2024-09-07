#pragma once
#include "CommonInclude.h"
#include "rongPlayer.h"
#include "rongPlayer2.h"
//원래 더블버퍼링 알고리즘은 dc 두개를 생성->
//dc1에 그림->
//다음 프레임에 dc2에 그림->dc2를 보여준다-> 이때 dc1에 그려진 도형을 지운다
//다음 프레임에 dc1에 그림->dc1을 보여준다-> 이때 dc2에 그려진 도형을 지운다
//위 과정을 반복.

//아래 클래스는 그냥 비트맵 두개를 가지고 그리고 
namespace rong
{
	class Application
	{
	public:
		Application();
		
		~Application() {};
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();
	
	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;//dc 안에 도화지 [1920][1080] 의 픽셀 2차원배열이라고 보면 됨. 저 픽셀 하나당 charR, charG,charB 1바이트씩 3바이트 짜리 구조체.

		UINT mWidth;
		UINT mHeight;

		Player mPlayer;
		Player2 mPlayer2;
	};
}

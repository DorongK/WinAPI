#pragma once
#include "CommonInclude.h"
#include "rongPlayer.h"
#include "rongPlayer2.h"
//���� ������۸� �˰����� dc �ΰ��� ����->
//dc1�� �׸�->
//���� �����ӿ� dc2�� �׸�->dc2�� �����ش�-> �̶� dc1�� �׷��� ������ �����
//���� �����ӿ� dc1�� �׸�->dc1�� �����ش�-> �̶� dc2�� �׷��� ������ �����
//�� ������ �ݺ�.

//�Ʒ� Ŭ������ �׳� ��Ʈ�� �ΰ��� ������ �׸��� 
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
		HBITMAP mBackBitmap;//dc �ȿ� ��ȭ�� [1920][1080] �� �ȼ� 2�����迭�̶�� ���� ��. �� �ȼ� �ϳ��� charR, charG,charB 1����Ʈ�� 3����Ʈ ¥�� ����ü.

		UINT mWidth;
		UINT mHeight;

		Player mPlayer;
		Player2 mPlayer2;
	};
}

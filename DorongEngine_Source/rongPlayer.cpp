#include "rongPlayer.h"
#include "rongInput.h"
#include "rongTime.h"


rong::Player::Player()
{

}

rong::Player::~Player()
{

}

void rong::Player::Update()
{
	const float speed = 200.0f;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		mX -= speed*Time::GetDeltaTime();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		mX += speed * Time::GetDeltaTime();

	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		mY -= speed * Time::GetDeltaTime();
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		mY += speed * Time::GetDeltaTime();
	}
}

void rong::Player::LateUpdate()
{

}

void rong::Player::Render(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
	//파랑브러쉬 선택. 그리고 함수의 반환값은 원래 사용하던 흰색배경인듯.
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);//디폴트 흰색배경을 찾아갈 수 있도록 메모리로 남겨놓는것.
	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);//디폴트 흰색배경을 찾아갈 수 있도록 메모리로 남겨놓는것.
	SelectObject(hdc, oldPen);

	Rectangle(hdc, 100.f + mX, 100.f + mY, 200.f + mX, 200.f + mY);
	//다시 dc에 흰색배경 선택.
	SelectObject(hdc, oldbrush);
	DeleteObject(brush);//위에 동적할당한 녀석들 삭제해줘야 메세지 루프반복마다 메모리가 쌓이지 않는다.
	DeleteObject(redPen);
}

#include "rongPlayer2.h"
#include "rongInput.h"

rong::Player2::Player2()
{
}

rong::Player2::~Player2()
{
}

void rong::Player2::Update()
{
	if (Input::GetKeyPressed(eKeyCode::A))
	{
		mX -= 0.01f;
	}
	if (Input::GetKeyPressed(eKeyCode::D))
	{
		mX += 0.01f;
	}
	if (Input::GetKeyPressed(eKeyCode::W))
	{
		mY -= 0.01f;
	}
	if (Input::GetKeyPressed(eKeyCode::S))
	{
		mY += 0.01f;
	}
}

void rong::Player2::LateUpdate()
{
}

void rong::Player2::Render(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(0, 255, 255));
	//파랑브러쉬 선택. 그리고 함수의 반환값은 원래 사용하던 흰색배경인듯.
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);//디폴트 흰색배경을 찾아갈 수 있도록 메모리로 남겨놓는것.
	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);//디폴트 흰색배경을 찾아갈 수 있도록 메모리로 남겨놓는것.
	SelectObject(hdc, oldPen);
	
	Rectangle(hdc, 400 + mX, 400 + mY, 500 + mX, 500 + mY);
	//다시 dc에 흰색배경 선택.
	SelectObject(hdc, oldbrush);
	DeleteObject(brush);//위에 동적할당한 녀석들 삭제해줘야 메세지 루프반복마다 메모리가 쌓이지 않는다.
	DeleteObject(redPen);
}

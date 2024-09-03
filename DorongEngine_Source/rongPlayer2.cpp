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
	//�Ķ��귯�� ����. �׸��� �Լ��� ��ȯ���� ���� ����ϴ� �������ε�.
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);//����Ʈ �������� ã�ư� �� �ֵ��� �޸𸮷� ���ܳ��°�.
	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);//����Ʈ �������� ã�ư� �� �ֵ��� �޸𸮷� ���ܳ��°�.
	SelectObject(hdc, oldPen);
	
	Rectangle(hdc, 400 + mX, 400 + mY, 500 + mX, 500 + mY);
	//�ٽ� dc�� ������ ����.
	SelectObject(hdc, oldbrush);
	DeleteObject(brush);//���� �����Ҵ��� �༮�� ��������� �޼��� �����ݺ����� �޸𸮰� ������ �ʴ´�.
	DeleteObject(redPen);
}

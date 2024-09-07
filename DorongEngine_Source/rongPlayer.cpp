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
	//�Ķ��귯�� ����. �׸��� �Լ��� ��ȯ���� ���� ����ϴ� �������ε�.
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);//����Ʈ �������� ã�ư� �� �ֵ��� �޸𸮷� ���ܳ��°�.
	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);//����Ʈ �������� ã�ư� �� �ֵ��� �޸𸮷� ���ܳ��°�.
	SelectObject(hdc, oldPen);

	Rectangle(hdc, 100.f + mX, 100.f + mY, 200.f + mX, 200.f + mY);
	//�ٽ� dc�� ������ ����.
	SelectObject(hdc, oldbrush);
	DeleteObject(brush);//���� �����Ҵ��� �༮�� ��������� �޼��� �����ݺ����� �޸𸮰� ������ �ʴ´�.
	DeleteObject(redPen);
}

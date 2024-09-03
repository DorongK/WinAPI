#include "rongGameObject.h"
namespace rong
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
	

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;

		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;

		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		//�Ķ��귯�� ����. �׸��� �Լ��� ��ȯ���� ���� ����ϴ� �������ε�.
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);//����Ʈ �������� ã�ư� �� �ֵ��� �޸𸮷� ���ܳ��°�.
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);//����Ʈ �������� ã�ư� �� �ֵ��� �޸𸮷� ���ܳ��°�.
		SelectObject(hdc, oldPen);
		
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		//�ٽ� dc�� ������ ����.
		SelectObject(hdc, oldbrush);
		DeleteObject(brush);//���� �����Ҵ��� �༮�� ��������� �޼��� �����ݺ����� �޸𸮰� ������ �ʴ´�.
		DeleteObject(redPen);
	}
}
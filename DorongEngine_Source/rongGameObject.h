#pragma once
#include "CommonInclude.h"

//�� Ŭ������ ���� ������Ʈ ��ü�� ��ü�� �������� ���� ���̱� ������ ���������Լ��� ������ �Žô�.
namespace rong
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Update() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render(HDC hdc) = 0;

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		};
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	protected:
		float mX;
		float mY;

	};

}

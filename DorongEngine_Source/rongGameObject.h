#pragma once
#include "CommonInclude.h"

//이 클래스는 게임 오브젝트 자체로 객체를 생성하지 않을 것이기 때문에 순수가상함수를 포함할 거시다.
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

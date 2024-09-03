#pragma once
#include "rongGameObject.h"

namespace rong
{
	class Player2 : public GameObject
	{
	public:
		Player2();
		~Player2();

		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};

}
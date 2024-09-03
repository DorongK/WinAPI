#pragma once
#include "rongGameObject.h"

namespace rong
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};

}

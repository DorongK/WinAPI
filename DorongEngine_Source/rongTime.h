#pragma once
#include "CommonInclude.h"

namespace rong
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float GetDeltaTime() { return DeltaTime; }

	private:
		static LARGE_INTEGER CpuFrequency;//해당 컴퓨터의 cpu 고유진동수(클럭)
		static LARGE_INTEGER PrevFrequency;//이전 프레임의 시간.
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTime;
	};
}


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
		static LARGE_INTEGER CpuFrequency;//�ش� ��ǻ���� cpu ����������(Ŭ��)
		static LARGE_INTEGER PrevFrequency;//���� �������� �ð�.
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTime;
	};
}


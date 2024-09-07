#include "rongTime.h"

namespace rong
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTime = 0.0f;

	void Time::Initialize()
	{
		QueryPerformanceFrequency(&CpuFrequency);//cpu 고유진동수
		QueryPerformanceCounter(&PrevFrequency);//프로그램 시작했을 때 현재 진동수
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);
		float frequencyGap 
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTime = frequencyGap / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;//다음 측정을 위한 이전 진동수를 현재 진동수로 업데이트.
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTime;
		float fps = 1.0f / DeltaTime;

		wchar_t str[50] = L"";
		swprintf_s(str,50, L"Fps : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}


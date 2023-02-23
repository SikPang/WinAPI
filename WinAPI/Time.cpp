#include "Time.h"

namespace ks
{
    double Time::deltaTime = 0.0l;
    LARGE_INTEGER Time::cpuFrequency = {};
    LARGE_INTEGER Time::prevFrequency = {};
    LARGE_INTEGER Time::curFrequency = {};

    void Time::Initialize()
    {
        // CPU 고유 진동 수 가져오기 (GHz)
        QueryPerformanceFrequency(&cpuFrequency);

        // 프로그램이 처음 시작했을 때 진동 수
        QueryPerformanceCounter(&prevFrequency);
    }

    void Time::Update()
    {
        QueryPerformanceCounter(&curFrequency);

        double difFrequency = curFrequency.QuadPart - prevFrequency.QuadPart;

        deltaTime = difFrequency / cpuFrequency.QuadPart;
        prevFrequency.QuadPart = curFrequency.QuadPart;
    }
    
    void Time::Render(HDC hdc)
    {
    
    }
    
    void Time::Release()
    {
    
    }
}
#include "Time.h"
#include "Application.h"
#include <cwchar>

namespace ks
{

    double Time::deltaTime = 0.0l;
    double Time::second = 0.0l;
    LARGE_INTEGER Time::cpuFrequency = {};
    LARGE_INTEGER Time::prevFrequency = {};
    LARGE_INTEGER Time::curFrequency = {};

    void Time::Initialize()
    {
        // CPU ���� ���� �� �������� (GHz)
        QueryPerformanceFrequency(&cpuFrequency);

        // ���α׷��� ó�� �������� �� ���� ��
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
        second += deltaTime;

        if (second > 1.0f)
        {
            HWND hWnd = application.GetHwnd();

            wchar_t szFloat[50] = {};
            float FPS = 1.0f / (float)deltaTime;
            swprintf_s(szFloat, 50, L"FPS : %d", (UINT)FPS);
            //int iLen = wcsnlen_s(szFloat, 50);
            SetWindowText(hWnd, szFloat);

            second = 0.0f;
        }
    }
    
    void Time::Release()
    {
    
    }
}
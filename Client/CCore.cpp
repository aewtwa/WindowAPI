#include "pch.h"
#include "CCore.h"

#include "CObject.h"

//CCore* CCore::g_pInst = nullptr;

CObject g_obj;

CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
}

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = {0, 0, m_ptResolution.x, m_ptResolution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd);

	g_obj.m_ptPOS = POINT{ m_ptResolution.x / 2, m_ptResolution.y / 2 };
	g_obj.m_ptScale = POINT{ 100, 100 };

	return S_OK;
}

void CCore::progress()
{
	static int callcount = 0;
	++callcount;
	static int iPrevCount = GetTickCount();

	int iCurCount = GetTickCount();
	if (GetTickCount() - iPrevCount > 1000)
	{
		iPrevCount = iCurCount;
		callcount = 0;
	}

	update();

	render();
}

void CCore::update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		g_obj.m_ptPOS.x -= 1;
	}


	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		g_obj.m_ptPOS.x+= 1;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		g_obj.m_ptPOS.y -= 1;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		g_obj.m_ptPOS.y += 1;
	}
}

void CCore::render()
{
	// 그리기
	Rectangle(m_hDC, g_obj.m_ptPOS.x - g_obj.m_ptScale.x / 2,
		g_obj.m_ptPOS.y - g_obj.m_ptScale.y / 2,
		g_obj.m_ptPOS.x + g_obj.m_ptScale.x / 2,
		g_obj.m_ptPOS.y + g_obj.m_ptScale.y / 2);
}
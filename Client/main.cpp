﻿// Client.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Client.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND      g_hWnd; // 메인 윈도우 핸들
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING);

    // 윈도우 정보 등록
    MyRegisterClass(hInstance);

    // 윈도우 생성
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // 단축키 테이블 정보 로딩
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));

    MSG msg;

    //SetTimer(g_hWnd, 0, 0, nullptr);

    // GetMessage
    // 메세지큐에서 메세지 확인될때까지 대기
    // msg.message == WM_QUIT인 경우 false를 반환 -> 프로그램 종료

    // PeekMessage
    // 메세지 유무와 관계없이 반환
    // 메세지큐에서 메세지를 확인한 경우 true, 메세지큐에 메세지가 없는 경우 false

    DWORD dwPrevCount = GetTickCount();
    DWORD dwAccCount = 0;


    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            int iTime = GetTickCount();
            if (WM_QUIT == msg.message)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

            int iAdd = (GetTickCount() - iTime);
            dwAccCount += iAdd;
        }

        // 메세지가 발생하지 않는 대부분의 시간
        else
        {
            // 메세지가 없는동안 호출
            DWORD dwCurCount = GetTickCount();
            if (dwCurCount - dwPrevCount > 1000)
            {
                float fRatio = (float)dwAccCount / 1000.f;

                wchar_t szBuff[50] = {};
                swprintf_s(szBuff, L"비율 : %f", fRatio);
                SetWindowText(g_hWnd, szBuff);

                dwPrevCount = dwCurCount;
                dwAccCount = 0;
            }

            // Game 코드 수행
            // 디자인 패턴(설계 유형)
            // 싱글톤 패턴
        }
    }

    //KillTimer(g_hWnd, 0);

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CLIENT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   g_hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!g_hWnd)
   {
      return FALSE;
   }

   ShowWindow(g_hWnd, nCmdShow);
   UpdateWindow(g_hWnd);

   return TRUE;
}

#include <vector>

using std::vector;

struct tObjInfo
{
    POINT g_ptObjPos;
    POINT g_ptObjScale;
};

vector<tObjInfo> g_vecInfo;

// 좌 상단
POINT g_ptLT;
// 우 하단
POINT g_ptRB;

bool bLbtnDown;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT: // 무효화 영역(Invalidate)이 발생한 경우
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // DC의 목적지는 hWnd
            // DC의 펜은 기본펜(Black)
            // DC의 브러쉬는 기본 브러쉬(White)

            // 직접 펜을 만들어서 DC에 적용
            HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
            HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
            
            // 기존 펜과 브러쉬 ID값을 받아 둠
            HPEN hDefaultPen = (HPEN)SelectObject(hdc, hRedPen);
            HBRUSH hDefaultBrush = (HBRUSH)SelectObject(hdc, hBlueBrush);

            // 변경된 펜과 브러쉬로 사각형 그림
            if (bLbtnDown)
            {
                Rectangle(hdc, g_ptLT.x, g_ptLT.y
                    , g_ptRB.x, g_ptRB.y);
            }

            for (size_t i = 0; i < g_vecInfo.size(); i++)
            {
                Rectangle(hdc
                    , g_vecInfo[i].g_ptObjPos.x - g_vecInfo[i].g_ptObjScale.x / 2
                    , g_vecInfo[i].g_ptObjPos.y - g_vecInfo[i].g_ptObjScale.y / 2
                    , g_vecInfo[i].g_ptObjPos.x + g_vecInfo[i].g_ptObjScale.x / 2
                    , g_vecInfo[i].g_ptObjPos.y + g_vecInfo[i].g_ptObjScale.y / 2);
            }

            // DC의 펜과 브러쉬를 원래 것으로 되돌림
            SelectObject(hdc, hDefaultPen);
            SelectObject(hdc, hDefaultBrush);

            // 다 쓴 Red펜 삭제 요청
            DeleteObject(hRedPen);
            DeleteObject(hBlueBrush);

            // 그리기 종료
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
    {
        switch (wParam)
        {
        case VK_UP:
            //g_ptObjPos.y -= 10;
            InvalidateRect(hWnd, nullptr, true);
            break;

        case VK_DOWN:
            //g_ptObjPos.y += 10;
            InvalidateRect(hWnd, nullptr, true);
            break;

        case VK_LEFT:
            //g_ptObjPos.x -= 10;
            InvalidateRect(hWnd, nullptr, true);
            break;

        case VK_RIGHT:
            //g_ptObjPos.x += 10;
            InvalidateRect(hWnd, nullptr, true);
            break;
        }
    }
    break;
    
    case WM_LBUTTONDOWN:
    {
        g_ptLT.x = LOWORD(lParam);
        g_ptLT.y = HIWORD(lParam);
        bLbtnDown = true;
    }
        break;

    case WM_MOUSEMOVE:
        g_ptRB.x = LOWORD(lParam);
        g_ptRB.y = HIWORD(lParam);
        InvalidateRect(hWnd, nullptr, true);
        break;

    case WM_LBUTTONUP:
    {
        tObjInfo info = {};
        info.g_ptObjPos.x = (g_ptLT.x + g_ptRB.x) / 2;
        info.g_ptObjPos.y = (g_ptLT.y + g_ptRB.y) / 2;

        info.g_ptObjScale.x = abs(g_ptLT.x - g_ptRB.x);
        info.g_ptObjScale.y = abs(g_ptLT.y - g_ptRB.y);

        g_vecInfo.push_back(info);
        bLbtnDown = false;
        InvalidateRect(hWnd, nullptr, true);
    }
    break;

    case WM_TIMER:
    {
        int a = 0;
    }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

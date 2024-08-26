// WindowEditor.cpp : 애플리케이션에 대한 진입점을 정의합니다.


#include "framework.h"
#include "WindowEditor.h"

//#pragma comment (lib,"..\\x64\\Debug\\DorongEngine_Win.lib")
#include "..\\DorongEngine_Source\\Dorong_Application.h"


#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, //얘는 핸들
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWEDITOR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWEDITOR));

    MSG msg;

    

    //PeekMessage : 메세지 유무와 상관없이 메세지 큐에  함수가 리턴된다.
    //              리턴값이 true면 메세지O false면 X라고 알려줌.
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            //메세지가 없을경우 여기서 처리
            //게임 로직이 들어감.
        }
    }
    //return을 만나 종료되지 않고 창이 계속 실행되도록 메세지루프
    //GetMessage(&msg, nullptr, 0, 0)
    //프로세스에서 발생한 메세지를 메세지 큐에서 가져오는 함수
    //메세지 큐에 아무것도 없다면 아무 메세지도 가져오지 않는다.(게임에 부적합)
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


//  용도: 창 클래스를 등록합니다. 아이콘 커서 색, 스타일 등등의 정보를 담고있다.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWEDITOR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWEDITOR);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   //크리에이트 윈도우 여러번 호출하면 윈도우 창도 여러개!

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)//메세지 스위치문으로 받아서 분기에 따라 명령 처리
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            //DC는 화면 출력에 필요한 모든 정보를 가진 데이터 구조체임
            // GDI 모듈이 관리한다.
            // 폰트,선의 굵기? 색상
            // 화면 출력에 필요한 모든 경우는 DC를 통해 진행한다(WinApi에서는)
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
            //파랑브러쉬 선택. 그리고 함수의 반환값은 원래 사용하던 흰색배경인듯.
            HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);//디폴트 흰색배경을 찾아갈 수 있도록 메모리로 남겨놓는것.

            Rectangle(hdc, 100, 100, 200, 200);
            //다시 dc에 흰색배경 선택.
            SelectObject(hdc, oldbrush);
            DeleteObject(brush);//위에 동적할당한 녀석들 삭제해줘야 메세지 루프반복마다 메모리가 쌓이지 않는다.


            HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
            HPEN oldPen = (HPEN)SelectObject(hdc, redPen);//디폴트 흰색배경을 찾아갈 수 있도록 메모리로 남겨놓는것.
           
            Ellipse(hdc, 200, 200, 300, 300);
            
            SelectObject(hdc, oldPen);
            DeleteObject(redPen);

            //자주 사용되는 GDI오브젝트를 스톡오브젝트 로 미리 만들어 둔게 있어서 보통 위처럼 Create로 생성하고 다시 삭제하는 과정없이 SelectObject만 사용해서 바꿔쓸 수 있다.
            HBRUSH Greybrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
            oldbrush = (HBRUSH)SelectObject(hdc, Greybrush);
            Rectangle(hdc, 400, 200, 500, 300);
            SelectObject(hdc, oldbrush);


            EndPaint(hWnd, &ps);
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

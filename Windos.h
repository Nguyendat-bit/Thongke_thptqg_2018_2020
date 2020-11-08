#pragma once
#include<Windows.h>
// Chinh sua kich thuoc cua so
class Windos {
public:

    void SetWindowSize(SHORT width, SHORT height)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        SMALL_RECT WindowSize;
        WindowSize.Top = 0;
        WindowSize.Left = 0;
        WindowSize.Right = width;
        WindowSize.Bottom = height;

        SetConsoleWindowInfo(hStdout, 1, &WindowSize);
    }
    // Chinh sua cua so buffer
    void SetScreenBufferSize(SHORT width, SHORT height)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD NewSize;
        NewSize.X = width;
        NewSize.Y = height;

        SetConsoleScreenBufferSize(hStdout, NewSize);
    }
    // Chan user thay doi kich thuoc
    void DisableResizeWindow()
    {
        HWND hWnd = GetConsoleWindow();
        SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
    }
    // xoa nut min,max,close
    void DisableCtrButton(bool Close, bool Min, bool Max)
    {
        HWND hWnd = GetConsoleWindow();
        HMENU hMenu = GetSystemMenu(hWnd, false);

        if (Close == 1)
        {
            DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
        }
        if (Min == 1)
        {
            DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
        }
        if (Max == 1)
        {
            DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
        }
    }
    // an hien 2 thanh cuon  
    // Cho = 0
    void ShowScrollbar(BOOL Show)
    {
        HWND hWnd = GetConsoleWindow();
        ShowScrollBar(hWnd, SB_BOTH, Show);
    }
    // Thay doi tilte



    // An hien con tro = 0
    void ShowCur(bool CursorVisibility)
    {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO ConCurInf;

        ConCurInf.dwSize = 10;
        ConCurInf.bVisible = CursorVisibility;

        SetConsoleCursorInfo(handle, &ConCurInf);
    }
};
class Womdows :public Windos
{
public:
    Womdows() {
        SetConsoleTitle(L"Tool_Diemthi_THPTQG");
        this->SetWindowSize(150, 65);
        this->SetScreenBufferSize(140, 9999999);
        this->DisableResizeWindow();
        this->DisableCtrButton(0, 1, 1);
        this->ShowScrollbar(0);
        this->ShowCur(0);
   }
};

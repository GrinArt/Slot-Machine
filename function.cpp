#include "header.h"

void chooseFont(int size)
{
  HANDLE hCon = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
  if (hCon != INVALID_HANDLE_VALUE)
  {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = size;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = 400;
    wcscpy_s(cfi.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(hCon, FALSE, &cfi);
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
  }
}
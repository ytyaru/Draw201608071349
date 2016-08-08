#include "GdiWndProc.h"

GdiWndProc::GdiWndProc(void) {}
GdiWndProc::~GdiWndProc(void) {}
void GdiWndProc::Initialize() {}
void GdiWndProc::Finalize() {}
LRESULT CALLBACK GdiWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_PAINT:
			HDC hdc;
			PAINTSTRUCT ps;
			LPTSTR lptStr = TEXT("Ç±ÇÃï∂éöóÒÇÕGDIÇ≈ï`âÊÇµÇƒÇ¢Ç‹Ç∑ÅB");
			hdc = BeginPaint(hWnd , &ps);
			TextOut(hdc , 10 , 10 , lptStr , _tcslen(lptStr));
			EndPaint(hWnd , &ps);
			break;
		//default:
		//	break;
	}
	return (0L);
}

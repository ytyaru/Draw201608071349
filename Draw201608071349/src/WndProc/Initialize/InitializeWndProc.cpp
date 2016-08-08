#include "InitializeWndProc.h"

InitializeWndProc::InitializeWndProc(void) {}
InitializeWndProc::~InitializeWndProc(void) {}
void InitializeWndProc::Initialize()
{
}
void InitializeWndProc::Finalize()
{
}
LRESULT CALLBACK InitializeWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
    	case WM_CREATE:
    		MessageBox(hWnd, _T("Window1 InitializeWndProc::PartWndProc"), _T("WM_CREATE"), MB_OK);
			SetWindowText(::GetActiveWindow(), _T("1:GDI, 2:GDI+, 3:DirectX9  1Å`3ÇÃÇ¢Ç∏ÇÍÇ©ÇÃÉLÅ[Çì¸óÕÇµÇƒâ∫Ç≥Ç¢ÅB"));
    		break;
		default:
			break;
	}
	return (0L);
}

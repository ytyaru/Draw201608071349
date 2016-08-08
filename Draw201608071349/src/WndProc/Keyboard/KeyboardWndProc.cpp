#include "KeyboardWndProc.h"

KeyboardWndProc::KeyboardWndProc(GraphicsArchitectureSetter* graphicsArchitectureSetter)
	: m_graphicsArchitectureSetter(graphicsArchitectureSetter) {}
KeyboardWndProc::~KeyboardWndProc(void) {}
void KeyboardWndProc::Initialize() {}
void KeyboardWndProc::Finalize() {}
LRESULT CALLBACK KeyboardWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_KEYDOWN:
			switch (wParam)
			{
			case 0x31: //VK_1: ASCIIコードと同一
			case 0x61: //VK_NUMPAD1:
				m_graphicsArchitectureSetter->Set(_T("GDI"));
				SetWindowText(::GetActiveWindow(), _T("GDIで描画しています。1:GDI, 2:GDI+, 3:DirectX9  1～3のいずれかのキーを入力して下さい。"));
				break;
			case 0x32: //VK_2: ASCIIコードと同一
			case 0x62: //VK_NUMPAD2:
				m_graphicsArchitectureSetter->Set(_T("GDI+"));
				SetWindowText(::GetActiveWindow(), _T("GDI+で描画しています。1:GDI, 2:GDI+, 3:DirectX9  1～3のいずれかのキーを入力して下さい。"));
				break;
			case 0x33: //VK_3: ASCIIコードと同一
			case 0x63: //VK_NUMPAD3:
				m_graphicsArchitectureSetter->Set(_T("DirectX9"));
				SetWindowText(::GetActiveWindow(), _T("DirectX9で描画しています。1:GDI, 2:GDI+, 3:DirectX9  1～3のいずれかのキーを入力して下さい。"));
				break;
			default:
				MessageBox(hWnd, _T("Window1 KeyboardWndProc::PartWndProc"), _T("WM_KEYDOWN"), MB_OK);
				break;
			}
			break;
		default:
			break;
	}
	return (0L);
}

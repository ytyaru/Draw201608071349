#pragma once
#include <windows.h>
#include <tchar.h>

namespace ytyaru {
namespace Framework {
namespace WndProc {
class IPartWndProc
{
public:
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn) = 0;
	virtual void Initialize() = 0;
	virtual void Finalize() = 0;
};
}
}
}

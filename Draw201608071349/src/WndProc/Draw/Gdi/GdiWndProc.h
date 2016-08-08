#pragma once
#include "IPartWndProc.h"

class GdiWndProc : public ytyaru::Framework::WndProc::IPartWndProc
{
public:
	GdiWndProc(void);
	~GdiWndProc(void);
	void Initialize();
	void Finalize();
	LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
};


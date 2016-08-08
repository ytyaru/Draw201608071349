#pragma once
#include "IPartWndProc.h"
#include <Windows.h>
#include <gdiplus.h>

class GdiPlusWndProc : public ytyaru::Framework::WndProc::IPartWndProc
{
public:
	GdiPlusWndProc(void);
	~GdiPlusWndProc(void);
	void Initialize();
	void Finalize();
	LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
private:
	void OnPaint(HDC hdc);
	Gdiplus::GdiplusStartupInput* m_gdiSI;
	ULONG_PTR m_gdiToken;
	Gdiplus::Bitmap* m_OffScreenBitmap;
	Gdiplus::Graphics* m_OffScreenGraphics;
};


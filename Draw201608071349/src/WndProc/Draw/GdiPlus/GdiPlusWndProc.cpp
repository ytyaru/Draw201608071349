#pragma comment(lib, "GdiPlus.lib")
#include "GdiPlusWndProc.h"
#include <sti.h>
using namespace Gdiplus;

GdiPlusWndProc::GdiPlusWndProc(void)
{
	m_OffScreenBitmap = NULL;
	m_OffScreenGraphics = NULL;
	m_gdiSI = NULL;
}
GdiPlusWndProc::~GdiPlusWndProc(void) {}
void GdiPlusWndProc::Initialize()
{
	if (NULL == m_gdiSI) {
		m_gdiSI = new Gdiplus::GdiplusStartupInput;
		GdiplusStartup(&m_gdiToken, m_gdiSI, NULL);
	}
	if (NULL == m_OffScreenBitmap) {
		m_OffScreenBitmap = new Bitmap(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
		m_OffScreenGraphics = Graphics::FromImage(m_OffScreenBitmap);
	}
}
void GdiPlusWndProc::Finalize()
{
	if (NULL != m_OffScreenGraphics) {
		m_OffScreenGraphics->Flush();
	}
	if (NULL != m_OffScreenBitmap) {;
		delete m_OffScreenBitmap;
		m_OffScreenBitmap = NULL;
	}
	if (NULL != m_OffScreenGraphics) {
		delete m_OffScreenGraphics;
		m_OffScreenGraphics = NULL;
	}
	if (NULL != m_gdiSI) {
		delete m_gdiSI;
		m_gdiSI = NULL;
		GdiplusShutdown(m_gdiToken);
	}
}
LRESULT CALLBACK GdiPlusWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_CREATE:
			Initialize();
			break;
		case WM_DESTROY:
			Finalize();
			break;
		case WM_ERASEBKGND:
			*pIsReturn = TRUE;
			return TRUE;
		case WM_PAINT:
			HDC hdc;
			PAINTSTRUCT ps;
			hdc = BeginPaint(hWnd , &ps);
			OnPaint(hdc);
			EndPaint(hWnd , &ps);
			break;
		default:
			break;
	}
	return (0L);
}
void GdiPlusWndProc::OnPaint(HDC hdc)
{
	Graphics g(hdc);

	m_OffScreenGraphics->Clear(Color::White);

	Gdiplus::Pen pen1(Color(255, 255, 0, 0), 5);
	m_OffScreenGraphics->DrawRectangle(&pen1, 0, 0, 200, 300);
	
	Gdiplus::Font font(L"‚l‚r ƒSƒVƒbƒN", 18);
	Gdiplus::SolidBrush blackBrush(Color(255, 0, 0, 0));
	Gdiplus::StringFormat format;
	format.SetAlignment(StringAlignmentCenter);
	m_OffScreenGraphics->DrawString(_T("‚±‚Ì•¶š—ñ‚ÍGDI+‚Å•`‰æ‚µ‚Ä‚¢‚Ü‚·B"), -1, &font, RectF(0.0f, 0.0f, 200.0f, 300.0f), &format, &blackBrush);

	g.DrawImage(m_OffScreenBitmap, 0, 0);
}
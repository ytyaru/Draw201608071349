#include "GraphicsArchitectureSetter.h"
#include "GdiWndProc.h"
#include "GdiPlusWndProc.h"
#include "DirectXWndProc.h"

using ytyaru::Framework::WndProc::Window;
using ytyaru::Framework::WndProc::IPartWndProc;

GraphicsArchitectureSetter::GraphicsArchitectureSetter(Window* pWindow)
{
	m_pWindow = pWindow;
	m_gdi = NULL;
	m_gdiPlus = NULL;
	m_directX9 = NULL;
	m_selected = NULL;
}
GraphicsArchitectureSetter::~GraphicsArchitectureSetter(void)
{
	Finalize();
}
void GraphicsArchitectureSetter::Initialize()
{
	if (NULL == m_gdi) { m_gdi = new GdiWndProc(); }
	if (NULL == m_gdiPlus) { m_gdiPlus = new GdiPlusWndProc(); }
	if (NULL == m_directX9) { m_directX9 = new DirectXWndProc(); }
	Set(_T("GDI"));
}
void GraphicsArchitectureSetter::Finalize()
{
	if (NULL != m_gdi) {
		delete m_gdi;
		m_gdi = NULL;
	}
	if (NULL != m_gdiPlus) {
		delete m_gdiPlus;
		m_gdiPlus = NULL;
	}
	if (NULL != m_directX9) {
		delete m_directX9;
		m_directX9 = NULL;
	}
}
void GraphicsArchitectureSetter::Set(const std::basic_string<TCHAR> &name)
{
	if (3 == _tcslen(name.c_str()) && 0 == _tcsnicmp(_T("GDI"), name.c_str(), 3)) { this->Change(m_gdi); }
	else if (0 == _tcsnicmp(_T("GDI+"), name.c_str(), 4)
		|| 0 == _tcsnicmp(_T("GDIPlus"), name.c_str(), 7)
		|| 0 == _tcsnicmp(_T("GDI_Plus"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("GDI-Plus"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("GDI Plus"), name.c_str(), 8)) { this->Change(m_gdiPlus); }
	else if (0 == _tcsnicmp(_T("DirectX9"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("DirectX_9"), name.c_str(), 9)
		|| 0 == _tcsnicmp(_T("DirectX-9"), name.c_str(), 9)
		|| 0 == _tcsnicmp(_T("DirectX 9"), name.c_str(), 9)) { this->Change(m_directX9); }
	else { this->Change(NULL); }
}
IPartWndProc* GraphicsArchitectureSetter::Get()
{
	return m_selected;
}
IPartWndProc* GraphicsArchitectureSetter::Get(const std::basic_string<TCHAR> &name)
{
	if (0 == _tcsnicmp(_T("GDI"), name.c_str(), 3)) { return m_gdi; }
	else if (0 == _tcsnicmp(_T("GDI+"), name.c_str(), 4)
		|| 0 == _tcsnicmp(_T("GDIPlus"), name.c_str(), 7)
		|| 0 == _tcsnicmp(_T("GDI_Plus"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("GDI-Plus"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("GDI Plus"), name.c_str(), 8)) { return m_gdiPlus; }
	else if (0 == _tcsnicmp(_T("DirectX9"), name.c_str(), 8)
		|| 0 == _tcsnicmp(_T("DirectX_9"), name.c_str(), 9)
		|| 0 == _tcsnicmp(_T("DirectX-9"), name.c_str(), 9)
		|| 0 == _tcsnicmp(_T("DirectX 9"), name.c_str(), 9)) { return m_directX9; }
	else { return NULL; }
}
void GraphicsArchitectureSetter::Change(ytyaru::Framework::WndProc::IPartWndProc* newProc)
{
	if (NULL == newProc) {
		if (NULL != m_selected) { 
			m_selected->Finalize();
			m_pWindow->Remove(m_selected);
		}
		m_selected = NULL;
		InvalidateRect(0, 0, FALSE); // âÊñ ëSëÃÇçƒï`âÊ
	}
	else if (m_selected != newProc) {
		if (NULL != m_selected) { 
			m_selected->Finalize();
			m_pWindow->Remove(m_selected);
		}
		m_selected = newProc;
		m_selected->Initialize();
		m_pWindow->Add(m_selected);
		InvalidateRect(0, 0, FALSE); // âÊñ ëSëÃÇçƒï`âÊ
	}
	else {}
}
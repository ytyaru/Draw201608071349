#pragma once
#include "Window.h"
#include "IPartWndProc.h"

class GraphicsArchitectureSetter
{
public:
    explicit GraphicsArchitectureSetter(ytyaru::Framework::WndProc::Window* pWindow);
    ~GraphicsArchitectureSetter();
	void Initialize();
	void Finalize();
    void Set(const std::basic_string<TCHAR> &name);
	ytyaru::Framework::WndProc::IPartWndProc* Get();
	ytyaru::Framework::WndProc::IPartWndProc* Get(const std::basic_string<TCHAR> &name);
private:
	void Change(ytyaru::Framework::WndProc::IPartWndProc* newProc);
    ytyaru::Framework::WndProc::Window* m_pWindow;
    ytyaru::Framework::WndProc::IPartWndProc* m_selected;
	ytyaru::Framework::WndProc::IPartWndProc* m_gdi;
	ytyaru::Framework::WndProc::IPartWndProc* m_gdiPlus;
	ytyaru::Framework::WndProc::IPartWndProc* m_directX9;
};

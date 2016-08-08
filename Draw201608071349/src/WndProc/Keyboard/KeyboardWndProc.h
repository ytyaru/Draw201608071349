#pragma once
#include "IPartWndProc.h"
#include "GraphicsArchitectureSetter.h"

class KeyboardWndProc : public ytyaru::Framework::WndProc::IPartWndProc
{
public:
	explicit KeyboardWndProc(GraphicsArchitectureSetter* graphicsArchitectureSetter);
	~KeyboardWndProc(void);
	void Initialize();
	void Finalize();
	LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
private:
	GraphicsArchitectureSetter* m_graphicsArchitectureSetter;
};

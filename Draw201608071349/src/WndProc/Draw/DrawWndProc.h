#pragma once
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <map>
#include <string>
#include "IPartWndProc.h"
#include "GraphicsArchitectureSetter.h"
#include "GdiWndProc.h"
#include "GdiPlusWndProc.h"
#include "DirectXWndProc.h"

// 描画アーキテクチャを選択する
class DrawWndProc : public ytyaru::Framework::WndProc::IPartWndProc
{
public:
	explicit DrawWndProc(GraphicsArchitectureSetter* graphicsArchitectureSetter);
	~DrawWndProc(void);
	LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
	void Initialize();
	void Finalize();
private:
	GraphicsArchitectureSetter* m_graphicsArchitectureSetter;
	ytyaru::Framework::WndProc::IPartWndProc* m_selected;
};


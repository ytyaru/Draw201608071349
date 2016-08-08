#pragma once
#include "IPartWndProc.h"
#include <Windows.h>
#include <d3d9.h>

class DirectXWndProc : public ytyaru::Framework::WndProc::IPartWndProc
{
public:
	DirectXWndProc(void);
	~DirectXWndProc(void);
	void Initialize();
	void Finalize();
	LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
private:
	void OnPaint();
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pD3DDev;
};


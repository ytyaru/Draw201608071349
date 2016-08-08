#include "DrawWndProc.h"
using std::vector;
using std::pair;
using std::basic_string;
using ytyaru::Framework::WndProc::IPartWndProc;

DrawWndProc::DrawWndProc(GraphicsArchitectureSetter* graphicsArchitectureSetter)
	: m_graphicsArchitectureSetter(graphicsArchitectureSetter) {}
DrawWndProc::~DrawWndProc(void) {}
void DrawWndProc::Initialize() {}
void DrawWndProc::Finalize() {}
LRESULT CALLBACK DrawWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	m_graphicsArchitectureSetter->Get()->PartWndProc(hWnd, uMsg, wParam, lParam, pIsReturn);
	return (0L);
}
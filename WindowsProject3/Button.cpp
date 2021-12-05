// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている方々のための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "Button.h"

LRESULT Button::WindowProc(HWND hButton, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_KEYDOWN   : return KeyHandler::FromHandle(GetParent(hButton))->Handle_WM_KEYDOWN(hButton, wParam, lParam) ? 0 : CallWindowProc(FromHandle(hButton)->wndproc, hButton, WM_KEYDOWN   , wParam, lParam);
	case WM_KEYUP     : return KeyHandler::FromHandle(GetParent(hButton))->Handle_WM_KEYUP  (hButton, wParam, lParam) ? 0 : CallWindowProc(FromHandle(hButton)->wndproc, hButton, WM_KEYUP     , wParam, lParam);
	case WM_GETDLGCODE: return                                                                                              CallWindowProc(FromHandle(hButton)->wndproc, hButton, WM_GETDLGCODE, wParam, lParam) | DLGC_WANTCHARS | DLGC_WANTARROWS;
	default           : return                                                                                              CallWindowProc(FromHandle(hButton)->wndproc, hButton, uMsg         , wParam, lParam);
	}
}
Button::Button(HWND hButton)
	: nIDDlgItem(GetDlgCtrlID(hButton))
	, wndproc(reinterpret_cast<WNDPROC>(GetWindowLongPtr(hButton, GWLP_WNDPROC)))
{
	SetWindowLongPtr(hButton, GWLP_WNDPROC , LONG_PTR(WindowProc));
	SetWindowLongPtr(hButton, GWLP_USERDATA, LONG_PTR(this      ));
}
auto Button::FromHandle(HWND hButton)->Button*
{
	return reinterpret_cast<Button*>(GetWindowLongPtr(hButton, GWLP_USERDATA));
}
HWND Button::GetDlgItem(HWND hDlg) const
{
	return ::GetDlgItem(hDlg, nIDDlgItem);
}

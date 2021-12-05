// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている方々のための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "KeyHandler.h"

KeyHandler::~KeyHandler()
{
}
void KeyHandler::ToHandle(HWND hDlg)
{
	SetWindowLongPtr(hDlg, DWLP_USER, LONG_PTR(this));
}
auto KeyHandler::FromHandle(HWND hDlg)->KeyHandler*
{
	return reinterpret_cast<KeyHandler*>(GetWindowLongPtr(hDlg, DWLP_USER));
}

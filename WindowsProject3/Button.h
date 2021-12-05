// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている方々のための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include "KeyHandler.h"
class Button
{
	int     nIDDlgItem;
	WNDPROC wndproc   ;
	static LRESULT CALLBACK WindowProc(HWND hButton, UINT uMsg, WPARAM wParam, LPARAM lParam);
public:
	static auto FromHandle(HWND hButton)->Button*;
	HWND GetDlgItem(HWND hDlg) const;
	Button(HWND hButton);
};

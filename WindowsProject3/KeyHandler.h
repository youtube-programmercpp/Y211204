// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている方々のための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include <Windows.h>
class KeyHandler
{
public:
	virtual ~KeyHandler();
	void ToHandle(HWND hDlg);
	static auto FromHandle(HWND hDlg)->KeyHandler*;
	virtual bool Handle_WM_KEYDOWN(HWND hButton, WPARAM wParam, LPARAM lParam) = 0;
	virtual bool Handle_WM_KEYUP  (HWND hButton, WPARAM wParam, LPARAM lParam) = 0;
};

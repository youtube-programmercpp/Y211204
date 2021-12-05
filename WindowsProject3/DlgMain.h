// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている方々のための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include "Button.h"
class DlgMain : public KeyHandler
{
	Button btnmap[5][4];

	DlgMain(HWND hDlg);
	static INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static UINT KeyToButtonID
	( UINT uVirtKey  
	, UINT uScanCode 
	);
public:
	bool Handle_WM_KEYDOWN(HWND hButton, WPARAM wParam, LPARAM lParam) override;
	bool Handle_WM_KEYUP  (HWND hButton, WPARAM wParam, LPARAM lParam) override;
	static INT_PTR DialogBoxParamW
	( _In_opt_ HINSTANCE hInstance     
	, _In_opt_ HWND      hWndParent    
	, _In_     LPARAM    dwInitParam   
	);
};

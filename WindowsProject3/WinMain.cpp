// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている方々のための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "DlgMain.h"
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <CommCtrl.h>
#pragma comment(lib, "comctl32.lib")

int APIENTRY wWinMain
( _In_     HINSTANCE hInstance
, _In_opt_ HINSTANCE hPrevInstance
, _In_     LPWSTR    lpCmdLine
, _In_     int       nCmdShow
)
{
	static const INITCOMMONCONTROLSEX icce = { sizeof icce, ICC_LINK_CLASS };
	InitCommonControlsEx(&icce);
	(void)DlgMain::DialogBoxParamW
	( /*_In_opt_ HINSTANCE hInstance     */hInstance
	, /*_In_opt_ HWND      hWndParent    */nullptr
	, /*_In_     LPARAM    dwInitParam   */0
	);
}

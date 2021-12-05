// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている方々のための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "DlgMain.h"
#include "resource.h"
#include <CommCtrl.h>
#include <algorithm>

DlgMain::DlgMain(HWND hDlg)
	: btnmap
		{ {GetDlgItem(hDlg, IDC_BUTTON_Inv ), GetDlgItem(hDlg, IDC_BUTTON_Square), GetDlgItem(hDlg, IDC_BUTTON_Sqrt), GetDlgItem(hDlg, IDC_BUTTON_Div) }
		, {GetDlgItem(hDlg, IDC_BUTTON7    ), GetDlgItem(hDlg, IDC_BUTTON8      ), GetDlgItem(hDlg, IDC_BUTTON9    ), GetDlgItem(hDlg, IDC_BUTTON_Mul) }
		, {GetDlgItem(hDlg, IDC_BUTTON4    ), GetDlgItem(hDlg, IDC_BUTTON5      ), GetDlgItem(hDlg, IDC_BUTTON6    ), GetDlgItem(hDlg, IDC_BUTTON_Sub) }
		, {GetDlgItem(hDlg, IDC_BUTTON1    ), GetDlgItem(hDlg, IDC_BUTTON2      ), GetDlgItem(hDlg, IDC_BUTTON3    ), GetDlgItem(hDlg, IDC_BUTTON_Add) }
		, {GetDlgItem(hDlg, IDC_BUTTON_Sign), GetDlgItem(hDlg, IDC_BUTTON0      ), GetDlgItem(hDlg, IDC_BUTTON_Dot ), GetDlgItem(hDlg, IDC_BUTTON_Equ) }
		}
{
}
UINT DlgMain::KeyToButtonID
( UINT uVirtKey  
, UINT uScanCode 
)
{
	BYTE keyboardState[256];
	if (GetKeyboardState(keyboardState)) {
		WORD wChar;
		if (ToAscii
		( /*_In_                UINT         uVirtKey  */uVirtKey  
		, /*_In_                UINT         uScanCode */uScanCode 
		, /*_In_reads_opt_(256) CONST BYTE * lpKeyState*/keyboardState
		, /*_Out_               LPWORD       lpChar    */&wChar
		, /*_In_                UINT         uFlags    */0
		) == 1) {
			switch (LOBYTE(wChar)) {
			case '0': return IDC_BUTTON0   ;
			case '1': return IDC_BUTTON1   ;
			case '2': return IDC_BUTTON2   ;
			case '3': return IDC_BUTTON3   ;
			case '4': return IDC_BUTTON4   ;
			case '5': return IDC_BUTTON5   ;
			case '6': return IDC_BUTTON6   ;
			case '7': return IDC_BUTTON7   ;
			case '8': return IDC_BUTTON8   ;
			case '9': return IDC_BUTTON9   ;
			case '.': return IDC_BUTTON_Dot;
			case '+': return IDC_BUTTON_Add;
			case '-': return IDC_BUTTON_Sub;
			case '*': return IDC_BUTTON_Mul;
			case '/': return IDC_BUTTON_Div;
			case '=': return IDC_BUTTON_Equ;
			}
		}
	}
	return 0;
}
bool DlgMain::Handle_WM_KEYDOWN(HWND hButton, WPARAM wParam, LPARAM lParam)
{
	switch (wParam) {
	case VK_UP   :
	{
		const auto sibling = Button::FromHandle(hButton) - _countof(*btnmap);
		if (sibling >= *btnmap) {
			const auto hDlg = GetParent(hButton);
			SendMessage(hDlg, WM_NEXTDLGCTL, WPARAM(sibling->GetDlgItem(hDlg)), true);
		}
		return true;
	}
	case VK_LEFT :
	{
		const auto pButton = Button::FromHandle(hButton);
		if ((pButton - *btnmap) % _countof(*btnmap)) {
			const auto hDlg = GetParent(hButton);
			SendMessage(hDlg, WM_NEXTDLGCTL, WPARAM(pButton[-1].GetDlgItem(hDlg)), true);
		}
		return true;
	}
	case VK_RIGHT:
	{
		const auto sibling = Button::FromHandle(hButton) + 1;
		if ((sibling - *btnmap) % _countof(*btnmap)) {
			const auto hDlg = GetParent(hButton);
			SendMessage(hDlg, WM_NEXTDLGCTL, WPARAM(sibling->GetDlgItem(hDlg)), true);
		}
		return true;
	}
	case VK_DOWN :
	{
		const auto sibling = Button::FromHandle(hButton) + _countof(*btnmap);
		if (sibling < *std::end(btnmap) - 1) {
			const auto hDlg = GetParent(hButton);
			SendMessage(hDlg, WM_NEXTDLGCTL, WPARAM(sibling->GetDlgItem(hDlg)), true);
		}
		return true;
	}
	default:
		if (const auto nID = KeyToButtonID
		( /*UINT uVirtKey  */static_cast<UINT>(wParam)
		, /*UINT uScanCode */LOBYTE(HIWORD(lParam))
		)) {
			const auto hDlg = GetParent(hButton);
			SendMessage(hDlg, DM_SETDEFID, nID, 0);
			SendDlgItemMessage(hDlg, nID, WM_LBUTTONDOWN, 0, 0);
			return true;
		}
		else
			return false;
	}
}
bool DlgMain::Handle_WM_KEYUP  (HWND hButton, WPARAM wParam, LPARAM lParam)
{
	if (const auto nID = KeyToButtonID
	( /*UINT uVirtKey  */static_cast<UINT>(wParam)
	, /*UINT uScanCode */LOBYTE(HIWORD(lParam))
	)) {
		SendDlgItemMessage(GetParent(hButton), nID, WM_LBUTTONUP, 0, 0);
		return true;
	}
	else
		return false;
}
INT_PTR CALLBACK DlgMain::DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_INITDIALOG:
		(new DlgMain(hDlg))->ToHandle(hDlg);
		return true;
	case WM_NCDESTROY :
		delete FromHandle(hDlg);
		return false;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_BUTTON0      : OutputDebugStringA("[" "0"    "]\n"); return true;
		case IDC_BUTTON1      : OutputDebugStringA("[" "1"    "]\n"); return true;
		case IDC_BUTTON2      : OutputDebugStringA("[" "2"    "]\n"); return true;
		case IDC_BUTTON3      : OutputDebugStringA("[" "3"    "]\n"); return true;
		case IDC_BUTTON4      : OutputDebugStringA("[" "4"    "]\n"); return true;
		case IDC_BUTTON5      : OutputDebugStringA("[" "5"    "]\n"); return true;
		case IDC_BUTTON6      : OutputDebugStringA("[" "6"    "]\n"); return true;
		case IDC_BUTTON7      : OutputDebugStringA("[" "7"    "]\n"); return true;
		case IDC_BUTTON8      : OutputDebugStringA("[" "8"    "]\n"); return true;
		case IDC_BUTTON9      : OutputDebugStringA("[" "9"    "]\n"); return true;
		case IDC_BUTTON_Sign  : OutputDebugStringA("[" "+/-"  "]\n"); return true;
		case IDC_BUTTON_Dot   : OutputDebugStringA("[" "."    "]\n"); return true;
		case IDC_BUTTON_Add   : OutputDebugStringA("[" "+"    "]\n"); return true;
		case IDC_BUTTON_Sub   : OutputDebugStringA("[" "-"    "]\n"); return true;
		case IDC_BUTTON_Mul   : OutputDebugStringA("[" "*"    "]\n"); return true;
		case IDC_BUTTON_Div   : OutputDebugStringA("[" "/"    "]\n"); return true;
		case IDC_BUTTON_Equ   : OutputDebugStringA("[" "="    "]\n"); return true;
		case IDC_BUTTON_Inv   : OutputDebugStringA("[" "1/x"  "]\n"); return true;
		case IDC_BUTTON_Square: OutputDebugStringA("[" "x^2"  "]\n"); return true;
		case IDC_BUTTON_Sqrt  : OutputDebugStringA("[" "sqrt" "]\n"); return true;
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return true;
		default:
			return false;
		}
	case WM_NOTIFY:
		if (wParam == IDC_SYSLINK1) {
			switch (LPNMHDR(lParam)->code) {
			case NM_CLICK :
			case NM_RETURN:
				ShellExecute(NULL, L"open", PNMLINK(lParam)->item.szUrl, NULL, NULL, SW_SHOW);
				return true;
			default:
				return false;
			}
		}
		else
			return false;
	default:
		return false;
	}
}
INT_PTR DlgMain::DialogBoxParamW
( _In_opt_ HINSTANCE hInstance     
, _In_opt_ HWND      hWndParent    
, _In_     LPARAM    dwInitParam   
)
{
	return ::DialogBoxParamW
	( /*_In_opt_ HINSTANCE hInstance     */hInstance     
	, /*_In_     LPCWSTR   lpTemplateName*/MAKEINTRESOURCEW(IDD_DIALOG_Main)
	, /*_In_opt_ HWND      hWndParent    */hWndParent    
	, /*_In_opt_ DLGPROC   lpDialogFunc  */DialogProc    
	, /*_In_     LPARAM    dwInitParam   */dwInitParam   
	);
}

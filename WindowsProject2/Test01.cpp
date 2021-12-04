#include "framework.h"
#include "WindowsProject2.h"
#include <sstream>
#include <iomanip>
std::string FormatKeyMsg(LPCSTR pszMsg, WPARAM wParam, LPARAM lParam)
{
    return (std::ostringstream()
        << std::setw(12) << std::left << pszMsg << std::right << std::setfill('0') << std::hex
        << ' ' << std::setw(2) << wParam
        << ' ' << std::setw(8) << lParam
        << '\n').str();
}
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_KEYDOWN: OutputDebugStringA(FormatKeyMsg("WM_KEYDOWN", wParam, lParam).c_str()); return false;
    case WM_KEYUP  : OutputDebugStringA(FormatKeyMsg("WM_KEYUP"  , wParam, lParam).c_str()); return false;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDCANCEL:
            EndDialog(hDlg, IDCANCEL);
            return true;
        case IDC_BUTTON1: OutputDebugStringA("[1]\n"); return true;
        case IDC_BUTTON2: OutputDebugStringA("[2]\n"); return true;
        case IDC_BUTTON3: OutputDebugStringA("[3]\n"); return true;
        case IDC_BUTTON4: OutputDebugStringA("[4]\n"); return true;
        case IDC_BUTTON5: OutputDebugStringA("[5]\n"); return true;
        case IDC_BUTTON6: OutputDebugStringA("[6]\n"); return true;
        case IDC_BUTTON7: OutputDebugStringA("[7]\n"); return true;
        case IDC_BUTTON8: OutputDebugStringA("[8]\n"); return true;
        case IDC_BUTTON9: OutputDebugStringA("[9]\n"); return true;


        default:
            return false;
        }
    default:
        return false;
    }
}


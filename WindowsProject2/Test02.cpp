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

struct NumBtn {
    static LRESULT CALLBACK WindowProc(HWND hButton, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        char szBuf[256];
        GetWindowTextA(hButton, szBuf, sizeof szBuf);
        const auto pThis = reinterpret_cast<NumBtn*>(GetWindowLongPtr(hButton, GWLP_USERDATA));
        switch (uMsg) {
        case WM_KEYDOWN: OutputDebugStringA(FormatKeyMsg("WM_KEYDOWN", wParam, lParam).c_str()); return CallWindowProc(pThis->wndproc, hButton, uMsg, wParam, lParam);
        case WM_KEYUP  : OutputDebugStringA(FormatKeyMsg("WM_KEYUP"  , wParam, lParam).c_str()); return CallWindowProc(pThis->wndproc, hButton, uMsg, wParam, lParam);
        default: return CallWindowProc(pThis->wndproc, hButton, uMsg, wParam, lParam);
        }
    }
    HWND    hButton;
    WNDPROC wndproc;
    NumBtn(HWND hDlg, UINT nID)
        : hButton(GetDlgItem(hDlg, nID))
        , wndproc(reinterpret_cast<WNDPROC>(GetWindowLongPtr(hButton, GWLP_WNDPROC)))
    {
    }
    void Install()
    {
        SetWindowLongPtr(hButton, GWLP_WNDPROC, LONG_PTR(WindowProc));
        SetWindowLongPtr(hButton, GWLP_USERDATA, LONG_PTR(this));
    }
    NumBtn() = default;
};
NumBtn btn1;
NumBtn btn2;
NumBtn btn3;
NumBtn btn4;
NumBtn btn5;
NumBtn btn6;
NumBtn btn7;
NumBtn btn8;
NumBtn btn9;

INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_INITDIALOG:
        (btn1 = {hDlg, IDC_BUTTON1}).Install();
        (btn2 = {hDlg, IDC_BUTTON2}).Install();
        (btn3 = {hDlg, IDC_BUTTON3}).Install();
        (btn4 = {hDlg, IDC_BUTTON4}).Install();
        (btn5 = {hDlg, IDC_BUTTON5}).Install();
        (btn6 = {hDlg, IDC_BUTTON6}).Install();
        (btn7 = {hDlg, IDC_BUTTON7}).Install();
        (btn8 = {hDlg, IDC_BUTTON8}).Install();
        (btn9 = {hDlg, IDC_BUTTON9}).Install();
        return true;
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


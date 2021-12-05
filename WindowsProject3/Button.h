// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă�����X�̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
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

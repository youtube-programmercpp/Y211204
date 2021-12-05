// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă�����X�̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
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

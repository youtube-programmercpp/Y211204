// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă�����X�̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
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

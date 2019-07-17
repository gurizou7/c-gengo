#include "stdafx.h"
#include"DxLib.h"
#include"Manager.h"
#include"Title.h"
#include"Game.h"
void CTitle::Update()
{
	if (manager->GetKey()[KEY_INPUT_X] >= 1)
	{
		//�Q�[���ɃV�[���ڍs
		manager->scene = new CGame(manager);
		delete this;
	}

}

void CTitle::Render()
{
	SetFontSize(50);                             //�T�C�Y��20�ɕύX
	SetFontThickness(1);                      //������8�ɕύX
	ChangeFont("HGS�n�p�p�߯�ߑ�");              //HGS�n�p�p�߯�ߑ̂ɕύX
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);//�A���`�G�C���A�X���G�b�W�t���t�H���g�ɕύX
	DrawFormatString(60, 150, GetColor(255, 255, 255), "�V���[�e�B���O�Q�[��");

	
	SetFontSize(30);                        //�T�C�Y��20�ɕύX
	SetFontThickness(8);                      //������1�ɕύX
	ChangeFont("HGS�n�p�p�߯�ߑ�");              //HGS�n�p�p�߯�ߑ̂ɕύX
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);//�A���`�G�C���A�X���G�b�W�t���t�H���g�ɕύX
	DrawFormatString(120, 300, GetColor(255, 255, 255), "PUSH X KEY");
}
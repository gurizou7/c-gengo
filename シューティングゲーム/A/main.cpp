// A.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include"DxLib.h"
#include"Manager.h"
#include"Title.h"
#include"Game.h"
class CGame;

#define KEY_NUM 256
//�L�[�̓��͏�Ԃ��X�V����
int gpUpdateKey(char *key) {
	//���݂̃L�[�̓��͏�Ԃ��i�[����
	char tmpKey[KEY_NUM];
	//�S�ẴL�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i<KEY_NUM; i++) {
		if (tmpKey[i] != 0)
		{//i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�������Z
			key[i]++;
		}
		else
		{//������Ă��Ȃ����0�ɂ���
			key[i] = 0;
		}
	}
	return 0;
}

#define BUFFSIZE 1024
bool Process(char *key) {
	if (ProcessMessage() != 0) return false;
	//��ʂ̗��y�[�W�̓��e��\�y�[�W�ɔ��f����
	if (ScreenFlip() != 0) return false;
	//��ʂ�������
	if (ClearDrawScreen() != 0) return false;
	//�L�[�擾
	if (gpUpdateKey(key) != 0) return false;
	//�G�X�P�[�v�ŏI��
	if (key[KEY_INPUT_ESCAPE] >= 1) {
	/*	FILE *fp;
		char s[BUFFSIZE];
		errno_t error;
		error = fopen_s(&fp, "SCORE.txt","w");
		if (error != 0){
			fprintf_s(stderr, "failed to open");
		}
		else {
			int cnt1 =
			//fputs("SCORE:", fp);
			//fputs(cnt1[6], fp);
			fprintf(fp, "SCORE:%d", cnt1);
			fclose(fp);
			
		}*/return false;
	}
	return true;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//�E�C���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	//DX���C�u����������������B
	if (DxLib_Init() == -1) return -1;
	//�L�[�擾
	char key[KEY_NUM];
	//�`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);
	//�Ǘ��V�X�e���𓮓I�m��
	CManager *manager;
	manager = new CManager(key);
	//�^�C�g���𓮓I�m��
	manager->scene = new CTitle(manager);
	while (Process(key))
	{
		//�Q�[�����[�v
		manager->Render();
		manager->Update();
	}
	//��n��
	delete manager;
	//DX���C�u�������I������B
	DxLib_End();

	return 0;
}
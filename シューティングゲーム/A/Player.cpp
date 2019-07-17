#include "stdafx.h"
#include"DxLib.h"
#include "Object.h"
#include"Player.h"
#include"Manager.h"
#include "BulletManager.h"
#define PLAYER_SPEED 10.0f



CPlayer::CPlayer(CManager *pManager)
{
	struct{
		
		int m_flag;             //�v�Z�Ώۂ�
		float pos;              //���W
		float p_speed;          //�G�̑���
		float p_angle;          //�G�̌���
		int m_count;            //�J�E���^
	
	};
	//CManager�̃A�h���X�i�[
	manager = pManager;
	//�摜�f�[�^�i�[
	graphic = new int;
	*graphic = LoadGraph("player.bmp");
	bulletGraphic = LoadGraph("shot.bmp");
	//�ʒu��������
	pos = VGet(320, 240, 0);
	range = 10;

}
CPlayer::~CPlayer()
{
	delete graphic;
}
void CPlayer::Render()
{
	// �ǂ݂��񂾃O���t�B�b�N����]�`��
	DrawRotaGraph(pos.x, pos.y, 1.0, 0, *graphic, TRUE);
}

void CPlayer::Update()
{
	//�ړ��������
	VECTOR vPos = VGet(0, 0, 0);
	//�e�̔��˂�}������g���K�[
	static int count = 0;
	//�ړ����Ă��Ȃ��Ƃ��͐��K������K�v���Ȃ��̂ł���ňړ����Ă��邩�m�F����
	bool moveFlag = false;
	if (manager->GetKey()[KEY_INPUT_LEFT] > 0)
	{
		vPos.x -= 1.0f;
		moveFlag = true;
	}
	if (manager->GetKey()[KEY_INPUT_RIGHT] > 0)
	{
		vPos.x += 1.0f;
		moveFlag = true;
	}
	if (manager->GetKey()[KEY_INPUT_UP] > 0)
	{
		vPos.y -= 1.0f;
		moveFlag = true;
	}
	if (manager->GetKey()[KEY_INPUT_DOWN] > 0)
	{
		vPos.y += 1.0f;
		moveFlag = true;
	}
	if (moveFlag && VSquareSize(vPos) != 0)//�������C��
	{
		vPos = VNorm(vPos);
		vPos = VScale(vPos, PLAYER_SPEED);
		//���݂̍��W�Ɉړ��ʂ����Z����
		pos = VAdd(pos, vPos);
	}
	//�e�̔���
	if (manager->GetKey()[KEY_INPUT_SPACE] > 0)
	{
		count++;
	}
	else
	{
		count = 0;
	}
	if ((count % 10) == 1)
	{
		//��ɒe���΂�
		bulletManager->Shot(&bulletGraphic, pos, VGet(0, -7, 0));
	}
}
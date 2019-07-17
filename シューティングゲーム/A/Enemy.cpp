#include "stdafx.h"
#include"DxLib.h"
#include"Define.h"
#include"Object.h"
#include"Enemy.h"

CEnemy::CEnemy(int *tex, VECTOR &position)
{
	graphic = tex;
	pos = position;
	flag = true;
	hp = 5;
	range = 10;
}

CEnemy::~CEnemy()
{


}
void CEnemy::Update()
{
	//���Ɉړ�
	vPos = VGet(0, 1, 0);
	pos = VAdd(pos, vPos);
	//��ʂ̏c�̒���+100�̐��l�܂œG������������悤�ɂ���
	if (pos.y > GAME_SCREEN_HEIGHT + 100)
	{
		//��ʓ��Ȃ�t���O�����ɖ߂�
		flag = false;
	}
}
void CEnemy::Render()
{
	// �ǂ݂��񂾃O���t�B�b�N����]�`��
	DrawRotaGraph(pos.x, pos.y, 1.0, 0, *graphic, TRUE);
}

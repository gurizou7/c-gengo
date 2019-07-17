#include "stdafx.h"
#include "DxLib.h"
#include "Object.h"
#include "Bullet.h"
#include "Define.h"



CBullet::CBullet(int *tex, VECTOR &position, VECTOR &vPosition)
{
	graphic = tex;
	pos = position;
	vPos = vPosition;
	flag = true;
	range = 10;

}
CBullet::~CBullet()
{
}

void CBullet::Update()
{
	pos = VAdd(pos, vPos);
	//��ʓ��ɂ��邩�m�F
	if (pos.x > GAME_SCREEN_WIDTH || pos.x < 0 ||
		pos.y > GAME_SCREEN_HEIGHT || pos.y < 0)
	{
		//��ʊO�Ȃ����
		flag = false;
	}
}
void CBullet::Render()
{
	// �ǂ݂��񂾃O���t�B�b�N����]�`��
	DrawRotaGraph(pos.x, pos.y, 1.0, 0, *graphic, TRUE);
}
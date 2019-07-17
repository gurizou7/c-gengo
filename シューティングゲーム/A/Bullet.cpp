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
	//画面内にいるか確認
	if (pos.x > GAME_SCREEN_WIDTH || pos.x < 0 ||
		pos.y > GAME_SCREEN_HEIGHT || pos.y < 0)
	{
		//画面外なら消す
		flag = false;
	}
}
void CBullet::Render()
{
	// 読みこんだグラフィックを回転描画
	DrawRotaGraph(pos.x, pos.y, 1.0, 0, *graphic, TRUE);
}
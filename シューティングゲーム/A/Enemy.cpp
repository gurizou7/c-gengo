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
	//下に移動
	vPos = VGet(0, 1, 0);
	pos = VAdd(pos, vPos);
	//画面の縦の長さ+100の数値まで敵が来たら消すようにする
	if (pos.y > GAME_SCREEN_HEIGHT + 100)
	{
		//画面内ならフラグを元に戻す
		flag = false;
	}
}
void CEnemy::Render()
{
	// 読みこんだグラフィックを回転描画
	DrawRotaGraph(pos.x, pos.y, 1.0, 0, *graphic, TRUE);
}

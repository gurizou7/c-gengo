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
		
		int m_flag;             //計算対象か
		float pos;              //座標
		float p_speed;          //敵の速さ
		float p_angle;          //敵の向き
		int m_count;            //カウンタ
	
	};
	//CManagerのアドレス格納
	manager = pManager;
	//画像データ格納
	graphic = new int;
	*graphic = LoadGraph("player.bmp");
	bulletGraphic = LoadGraph("shot.bmp");
	//位置を初期化
	pos = VGet(320, 240, 0);
	range = 10;

}
CPlayer::~CPlayer()
{
	delete graphic;
}
void CPlayer::Render()
{
	// 読みこんだグラフィックを回転描画
	DrawRotaGraph(pos.x, pos.y, 1.0, 0, *graphic, TRUE);
}

void CPlayer::Update()
{
	//移動する向き
	VECTOR vPos = VGet(0, 0, 0);
	//弾の発射を抑制するトリガー
	static int count = 0;
	//移動していないときは正規化する必要がないのでこれで移動しているか確認する
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
	if (moveFlag && VSquareSize(vPos) != 0)//ここを修正
	{
		vPos = VNorm(vPos);
		vPos = VScale(vPos, PLAYER_SPEED);
		//現在の座標に移動量を加算する
		pos = VAdd(pos, vPos);
	}
	//弾の発射
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
		//上に弾を飛ばす
		bulletManager->Shot(&bulletGraphic, pos, VGet(0, -7, 0));
	}
}
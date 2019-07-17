#include "stdafx.h"
#include"DxLib.h"
#include"Object.h"
#include"Enemy.h"
#include"EnemyManager.h"
#include"Define.h"

CEnemyManager::CEnemyManager()
{
	for (int num = 0; num < ENEMY_NUM; num++)
	{
		enemy[num] = NULL;
	}
	//敵の画像読み込み
	enemyGraphic = LoadGraph("t.png");
}
CEnemyManager::~CEnemyManager()
{

	for (int num = 0; num < ENEMY_NUM; num++)
	{
		delete enemy[num];
	}
}


void CEnemyManager::Update()
{
	//生成
	Spawn();
	for (int num = 0; num < ENEMY_NUM; num++)
	{
		//NULLでない場合
		if (enemy[num] != NULL)
		{
			enemy[num]->Update();
			//弾が画面外に出た場合
			if (enemy[num]->GetFlag() == false)
			{
				//削除してからNULLを入れる
				delete enemy[num];
				enemy[num] = NULL;
			}
		}
	}
}
void CEnemyManager::Render()
{
	for (int num = 0; num < ENEMY_NUM; num++)
	{
		//NULLでない場合
		if (enemy[num] != NULL)
		{
			enemy[num]->Render();
		}
	}
}

void CEnemyManager::Spawn()
{
	//一定確立で敵が出現
	if ((rand() % 100) == 0)
	{
		for (int num = 0; num < ENEMY_NUM; num++)
		{
			//NULLの場合
			if (enemy[num] == NULL)
			{
				//敵を生成するX軸を決める
				int yPos = (rand() % (GAME_SCREEN_WIDTH));
				//敵生成
				enemy[num] = new CEnemy(&enemyGraphic, VGet(yPos, 0, 0));
				//一体生成したら抜けるようにする
				break;
			}
		}
	}
}
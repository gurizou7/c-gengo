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
	//“G‚Ì‰æ‘œ“Ç‚İ‚İ
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
	//¶¬
	Spawn();
	for (int num = 0; num < ENEMY_NUM; num++)
	{
		//NULL‚Å‚È‚¢ê‡
		if (enemy[num] != NULL)
		{
			enemy[num]->Update();
			//’e‚ª‰æ–ÊŠO‚Éo‚½ê‡
			if (enemy[num]->GetFlag() == false)
			{
				//íœ‚µ‚Ä‚©‚çNULL‚ğ“ü‚ê‚é
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
		//NULL‚Å‚È‚¢ê‡
		if (enemy[num] != NULL)
		{
			enemy[num]->Render();
		}
	}
}

void CEnemyManager::Spawn()
{
	//ˆê’èŠm—§‚Å“G‚ªoŒ»
	if ((rand() % 100) == 0)
	{
		for (int num = 0; num < ENEMY_NUM; num++)
		{
			//NULL‚Ìê‡
			if (enemy[num] == NULL)
			{
				//“G‚ğ¶¬‚·‚éX²‚ğŒˆ‚ß‚é
				int yPos = (rand() % (GAME_SCREEN_WIDTH));
				//“G¶¬
				enemy[num] = new CEnemy(&enemyGraphic, VGet(yPos, 0, 0));
				//ˆê‘Ì¶¬‚µ‚½‚ç”²‚¯‚é‚æ‚¤‚É‚·‚é
				break;
			}
		}
	}
}
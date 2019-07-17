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
	//�G�̉摜�ǂݍ���
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
	//����
	Spawn();
	for (int num = 0; num < ENEMY_NUM; num++)
	{
		//NULL�łȂ��ꍇ
		if (enemy[num] != NULL)
		{
			enemy[num]->Update();
			//�e����ʊO�ɏo���ꍇ
			if (enemy[num]->GetFlag() == false)
			{
				//�폜���Ă���NULL������
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
		//NULL�łȂ��ꍇ
		if (enemy[num] != NULL)
		{
			enemy[num]->Render();
		}
	}
}

void CEnemyManager::Spawn()
{
	//���m���œG���o��
	if ((rand() % 100) == 0)
	{
		for (int num = 0; num < ENEMY_NUM; num++)
		{
			//NULL�̏ꍇ
			if (enemy[num] == NULL)
			{
				//�G�𐶐�����X�������߂�
				int yPos = (rand() % (GAME_SCREEN_WIDTH));
				//�G����
				enemy[num] = new CEnemy(&enemyGraphic, VGet(yPos, 0, 0));
				//��̐��������甲����悤�ɂ���
				break;
			}
		}
	}
}
#include "stdafx.h"
#include "DxLib.h"
#include "Object.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "EnemyManager.h"

CBulletManager::CBulletManager()
{
	for (int num = 0; num < BULLET_NUM; num++)
	{
		bullet[num] = NULL;
	}

}
CBulletManager::~CBulletManager()
{
	for (int num = 0; num < BULLET_NUM; num++)
	{
		delete bullet[num];
	}
}

void CBulletManager::Shot(int *tex, VECTOR &pos, VECTOR &vPos)
{
	for (int num = 0; num < BULLET_NUM; num++)
	{
		if (bullet[num] == NULL)
		{
			bullet[num] = new CBullet(tex, pos, vPos);
			break;
		}
	}
}

void CBulletManager::Update()
{
	for (int num = 0; num < BULLET_NUM; num++)
	{
		//NULL�łȂ��ꍇ
		if (bullet[num] != NULL)
		{
			bullet[num]->Update();
			//�e����ʊO�ɏo���ꍇ
			if (bullet[num]->GetFlag() == false)
			{
				//�폜���Ă���NULL������
				delete bullet[num];
				bullet[num] = NULL;
			}
		}
	}
}
void CBulletManager::Render()
{
	for (int num = 0; num < BULLET_NUM; num++)
	{
		//NULL�łȂ��ꍇ
		if (bullet[num] != NULL)
		{
			bullet[num]->Render();
		}
	}
}

CObject *CBulletManager::GetBullet(int num) { return (CObject*)bullet[num]; }
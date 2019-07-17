#include "stdafx.h"
#include"DxLib.h"
#include"Manager.h"
#include"Game.h"
#include "Object.h"
#include "Player.h"
#include "BulletManager.h"
#include"EnemyManager.h"
#include <windows.h>
#define BUFFSIZE 1024
#define CHARBUFF 124

void getGurrentDirectory(char *currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}


void CGame::Update()
{

	char str[CHARBUFF]="hoghoe";
	DWORD nSize = sizeof(str);
	GetPrivateProfleString("section1", "keyword1", "hogehoge" , str, "data.ini");
	
	player->Update();
	bulletManager->Update();
	enemyManager->Update();
	struct {
		char name[20];
		double heikin;
	};

	//当たり判定
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bulletManager->GetBullet(i) != NULL)
		{
			for (int j = 0; j < BULLET_NUM; j++)
			{
				if (enemyManager->GetEnemy(j) != NULL)
				{
					ChackHitCircle(bulletManager->GetBullet(i), enemyManager->GetEnemy(j)); {
						cnt++;
					}
					FILE *fp;
					char s[BUFFSIZE];
					errno_t error;
					error = fopen_s(&fp, "SCORE.txt", "w");
					if (error != 0) {
						fprintf_s(stderr, "failed to open");
					}
					else {
						
							//fputs("SCORE:", fp);
							//fputs(cnt1[6], fp);
							fprintf(fp, "%s:SCORE:%d",str,cnt);
						fclose(fp);
					}
				}
			}
		}
	}
	//char c[] = { cnt };


}
void CGame::Render()
{
	player->Render();
	bulletManager->Render();
	enemyManager->Render();
}

int CGame::GetPrivateProfleString(const char * secton, const char * keyword, const char * defaultValue, const char * returnValue, const char * flePath)
{
	return 0;
}

CGame::CGame(CManager *pManager) : CScene(pManager)
{
	//プレイヤーを動的確保
	player = new CPlayer(pManager);
	//CBulletManagerを動的確保
	bulletManager = new CBulletManager();
	//CEnemyManagerを動的確保
	enemyManager = new CEnemyManager();
	//CBulletManagerクラスのアドレス取得
	player->SetBulletManager(bulletManager);
}
CGame::~CGame()
{
	//動的確保したものを解放する
	delete player;
	delete bulletManager;
	delete enemyManager;
}
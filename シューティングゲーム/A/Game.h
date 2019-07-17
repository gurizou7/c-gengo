#pragma once
class CPlayer;
class CBulletManager;
class CEnemyManager;
#include <windows.h>

class CGame :public CScene
{
	int cnt = 0;
	int GetPrivateProfleString(const char *secton, const char *keyword, const char *defaultValue, const char *returnValue, const char *flePath);
	//自機のポインタ変数
	CPlayer *player;
	//弾全体管理しているクラスのポインタ変数
	CBulletManager *bulletManager;
	//敵全体を管理しているクラスのポインタ変数
	CEnemyManager *enemyManager;
public:
	CGame(CManager *pManager);
	~CGame();
	void Update();
	void Render();
};
#pragma once
class CPlayer;
class CBulletManager;
class CEnemyManager;
#include <windows.h>

class CGame :public CScene
{
	int cnt = 0;
	int GetPrivateProfleString(const char *secton, const char *keyword, const char *defaultValue, const char *returnValue, const char *flePath);
	//���@�̃|�C���^�ϐ�
	CPlayer *player;
	//�e�S�̊Ǘ����Ă���N���X�̃|�C���^�ϐ�
	CBulletManager *bulletManager;
	//�G�S�̂��Ǘ����Ă���N���X�̃|�C���^�ϐ�
	CEnemyManager *enemyManager;
public:
	CGame(CManager *pManager);
	~CGame();
	void Update();
	void Render();
};
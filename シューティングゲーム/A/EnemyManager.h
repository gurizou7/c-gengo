#pragma once
class CEnemy;
//“G‚Ì”
#define ENEMY_NUM 100
class CEnemyManager
{
	CEnemy *enemy[ENEMY_NUM];
	//“G‚Ì‰æ‘œ
	int enemyGraphic;
public:
	CEnemyManager();
	~CEnemyManager();
	void Update();
	void Render();
	CObject *GetEnemy(int num) { return (CObject*)enemy[num]; }
private:
	//“G‚Ì¶¬
	void Spawn();
};
#pragma once
class CEnemy;
//�G�̐�
#define ENEMY_NUM 100
class CEnemyManager
{
	CEnemy *enemy[ENEMY_NUM];
	//�G�̉摜
	int enemyGraphic;
public:
	CEnemyManager();
	~CEnemyManager();
	void Update();
	void Render();
	CObject *GetEnemy(int num) { return (CObject*)enemy[num]; }
private:
	//�G�̐���
	void Spawn();
};
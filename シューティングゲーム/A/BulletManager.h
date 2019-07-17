#pragma once
class CBullet;
//íeÇÃêî
#define BULLET_NUM 100
class CBulletManager
{
	CBullet *bullet[BULLET_NUM];

public:
	CBulletManager();
	~CBulletManager();
	void Shot(int *tex, VECTOR &pos, VECTOR &vPos);
	void Update();
	void Render();
	CObject * GetBullet(int num);
};
typedef struct {
	double x, y;
	int flag;
} SHOT_t;


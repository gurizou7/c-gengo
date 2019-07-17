#pragma once

class CEnemy : public CObject
{
	struct data {
	VECTOR	vPos ;
	bool flag ;
	int	hp ;
	
	};
protected:
	//敵のHP
	int hp;
	//進む方向ベクトル
	VECTOR vPos;
	//敵の生存フラグ(true = 生きている)
	bool flag;
public:
	CEnemy() {};
	CEnemy(int *tex, VECTOR &position);
	~CEnemy();
	//描画
	void Render();
	//更新
	void Update();
	//敵の生存フラグを取得
	bool GetFlag() { return flag; };
	void HitAction() { flag = false; }
};
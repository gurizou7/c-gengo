#pragma once
//弾の管理
class CBullet :public CObject
{
	//進む方向ベクトル
	VECTOR vPos;
	//弾の生存フラグ(true = 生きている)
	bool flag;
public:
	CBullet() {};
	CBullet(int *tex, VECTOR &position, VECTOR &vPosition);
	~CBullet();
	//描画
	void Render();
	//更新
	void Update();
	//弾の生存フラグを取得
	bool GetFlag() { return flag; };
	void HitAction() { flag = false; }

};

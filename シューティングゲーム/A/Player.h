#pragma once
class CManager;
//これがないとエラーが出る
class CBulletManager;
class CPlayer :public CObject
{
	CManager *manager;
	//弾の画像
	int bulletGraphic;
	CBulletManager *bulletManager;
public:
	//コンストラクタ（インスタンス生成時に最初に呼ばれる関数）
	CPlayer(CManager *);
	//デストラクタ（インスタンス削除時に呼ばれる関数）
	~CPlayer();
	//描画
	void Render();
	//更新
	void Update();
	//bulletManagerのアドレスを取得
	void SetBulletManager(CBulletManager *bullet) { bulletManager = bullet; }
};

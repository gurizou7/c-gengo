#pragma once


class CObject
{
protected:
	//DXライブラリで定義されている構造体（中身はfloat型のx,y,z）
	VECTOR pos;
	//画像データ格納
	int *graphic;
	//あたり範囲
	float range;
public:
	//コンストラクタ（インスタンス生成時に最初に呼ばれる関数）
	CObject() {};
	//デストラクタ（インスタンス削除時に呼ばれる関数）
	virtual ~CObject() {};
	//描画
	virtual void Render() = 0;
	//更新
	virtual void Update() = 0;

	//posのアドレスを渡す関数
	VECTOR *GetPos() { return &pos; }
	//rangeの値を返す関数
	float GetRange() { return range; }
	//当たった時の処理(全て処理が違うので仮想関数にする)
	virtual void HitAction() {};
};

void ChackHitCircle(CObject *obj1, CObject *obj2);
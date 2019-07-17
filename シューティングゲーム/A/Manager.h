#pragma once
class CManager;
//シーンの基底クラス
class CScene
{
protected:
	CManager *manager;
public:
	CScene(CManager *pManager) { manager = pManager; };
	virtual ~CScene() {};
	//描画
	virtual void Update() {};
	//更新
	virtual void Render() {};
};
//シーン管理クラス
class CManager
{
	//キー
	char *key;
public:
	//今のシーンのポインタ
	CScene *scene;
	CManager(char *pKey) { key = pKey; };
	~CManager() { delete scene; };
	char *GetKey() { return key; }
	//描画
	void Update() { scene->Update(); };
	//更新
	void Render() { scene->Render(); };

};
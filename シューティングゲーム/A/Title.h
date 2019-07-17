#pragma once
//タイトル全体の管理
class CTitle :public CScene
{
public:
	CTitle(CManager *pManager) :CScene(pManager) {};
	~CTitle() {};
	void Update();
	void Render();
};
#pragma once
//�^�C�g���S�̂̊Ǘ�
class CTitle :public CScene
{
public:
	CTitle(CManager *pManager) :CScene(pManager) {};
	~CTitle() {};
	void Update();
	void Render();
};
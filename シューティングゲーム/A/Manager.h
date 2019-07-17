#pragma once
class CManager;
//�V�[���̊��N���X
class CScene
{
protected:
	CManager *manager;
public:
	CScene(CManager *pManager) { manager = pManager; };
	virtual ~CScene() {};
	//�`��
	virtual void Update() {};
	//�X�V
	virtual void Render() {};
};
//�V�[���Ǘ��N���X
class CManager
{
	//�L�[
	char *key;
public:
	//���̃V�[���̃|�C���^
	CScene *scene;
	CManager(char *pKey) { key = pKey; };
	~CManager() { delete scene; };
	char *GetKey() { return key; }
	//�`��
	void Update() { scene->Update(); };
	//�X�V
	void Render() { scene->Render(); };

};
#pragma once
class CManager;
//���ꂪ�Ȃ��ƃG���[���o��
class CBulletManager;
class CPlayer :public CObject
{
	CManager *manager;
	//�e�̉摜
	int bulletGraphic;
	CBulletManager *bulletManager;
public:
	//�R���X�g���N�^�i�C���X�^���X�������ɍŏ��ɌĂ΂��֐��j
	CPlayer(CManager *);
	//�f�X�g���N�^�i�C���X�^���X�폜���ɌĂ΂��֐��j
	~CPlayer();
	//�`��
	void Render();
	//�X�V
	void Update();
	//bulletManager�̃A�h���X���擾
	void SetBulletManager(CBulletManager *bullet) { bulletManager = bullet; }
};

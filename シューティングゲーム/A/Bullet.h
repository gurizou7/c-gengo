#pragma once
//�e�̊Ǘ�
class CBullet :public CObject
{
	//�i�ޕ����x�N�g��
	VECTOR vPos;
	//�e�̐����t���O(true = �����Ă���)
	bool flag;
public:
	CBullet() {};
	CBullet(int *tex, VECTOR &position, VECTOR &vPosition);
	~CBullet();
	//�`��
	void Render();
	//�X�V
	void Update();
	//�e�̐����t���O���擾
	bool GetFlag() { return flag; };
	void HitAction() { flag = false; }

};

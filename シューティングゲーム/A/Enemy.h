#pragma once

class CEnemy : public CObject
{
	struct data {
	VECTOR	vPos ;
	bool flag ;
	int	hp ;
	
	};
protected:
	//�G��HP
	int hp;
	//�i�ޕ����x�N�g��
	VECTOR vPos;
	//�G�̐����t���O(true = �����Ă���)
	bool flag;
public:
	CEnemy() {};
	CEnemy(int *tex, VECTOR &position);
	~CEnemy();
	//�`��
	void Render();
	//�X�V
	void Update();
	//�G�̐����t���O���擾
	bool GetFlag() { return flag; };
	void HitAction() { flag = false; }
};
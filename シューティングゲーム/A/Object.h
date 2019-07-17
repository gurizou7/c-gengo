#pragma once


class CObject
{
protected:
	//DX���C�u�����Œ�`����Ă���\���́i���g��float�^��x,y,z�j
	VECTOR pos;
	//�摜�f�[�^�i�[
	int *graphic;
	//������͈�
	float range;
public:
	//�R���X�g���N�^�i�C���X�^���X�������ɍŏ��ɌĂ΂��֐��j
	CObject() {};
	//�f�X�g���N�^�i�C���X�^���X�폜���ɌĂ΂��֐��j
	virtual ~CObject() {};
	//�`��
	virtual void Render() = 0;
	//�X�V
	virtual void Update() = 0;

	//pos�̃A�h���X��n���֐�
	VECTOR *GetPos() { return &pos; }
	//range�̒l��Ԃ��֐�
	float GetRange() { return range; }
	//�����������̏���(�S�ď������Ⴄ�̂ŉ��z�֐��ɂ���)
	virtual void HitAction() {};
};

void ChackHitCircle(CObject *obj1, CObject *obj2);
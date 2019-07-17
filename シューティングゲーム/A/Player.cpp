#include "stdafx.h"
#include"DxLib.h"
#include "Object.h"
#include"Player.h"
#include"Manager.h"
#include "BulletManager.h"
#define PLAYER_SPEED 10.0f



CPlayer::CPlayer(CManager *pManager)
{
	struct{
		
		int m_flag;             //ŒvŽZ‘ÎÛ‚©
		float pos;              //À•W
		float p_speed;          //“G‚Ì‘¬‚³
		float p_angle;          //“G‚ÌŒü‚«
		int m_count;            //ƒJƒEƒ“ƒ^
	
	};
	//CManager‚ÌƒAƒhƒŒƒXŠi”[
	manager = pManager;
	//‰æ‘œƒf[ƒ^Ši”[
	graphic = new int;
	*graphic = LoadGraph("player.bmp");
	bulletGraphic = LoadGraph("shot.bmp");
	//ˆÊ’u‚ð‰Šú‰»
	pos = VGet(320, 240, 0);
	range = 10;

}
CPlayer::~CPlayer()
{
	delete graphic;
}
void CPlayer::Render()
{
	// “Ç‚Ý‚±‚ñ‚¾ƒOƒ‰ƒtƒBƒbƒN‚ð‰ñ“]•`‰æ
	DrawRotaGraph(pos.x, pos.y, 1.0, 0, *graphic, TRUE);
}

void CPlayer::Update()
{
	//ˆÚ“®‚·‚éŒü‚«
	VECTOR vPos = VGet(0, 0, 0);
	//’e‚Ì”­ŽË‚ð—}§‚·‚éƒgƒŠƒK[
	static int count = 0;
	//ˆÚ“®‚µ‚Ä‚¢‚È‚¢‚Æ‚«‚Í³‹K‰»‚·‚é•K—v‚ª‚È‚¢‚Ì‚Å‚±‚ê‚ÅˆÚ“®‚µ‚Ä‚¢‚é‚©Šm”F‚·‚é
	bool moveFlag = false;
	if (manager->GetKey()[KEY_INPUT_LEFT] > 0)
	{
		vPos.x -= 1.0f;
		moveFlag = true;
	}
	if (manager->GetKey()[KEY_INPUT_RIGHT] > 0)
	{
		vPos.x += 1.0f;
		moveFlag = true;
	}
	if (manager->GetKey()[KEY_INPUT_UP] > 0)
	{
		vPos.y -= 1.0f;
		moveFlag = true;
	}
	if (manager->GetKey()[KEY_INPUT_DOWN] > 0)
	{
		vPos.y += 1.0f;
		moveFlag = true;
	}
	if (moveFlag && VSquareSize(vPos) != 0)//‚±‚±‚ðC³
	{
		vPos = VNorm(vPos);
		vPos = VScale(vPos, PLAYER_SPEED);
		//Œ»Ý‚ÌÀ•W‚ÉˆÚ“®—Ê‚ð‰ÁŽZ‚·‚é
		pos = VAdd(pos, vPos);
	}
	//’e‚Ì”­ŽË
	if (manager->GetKey()[KEY_INPUT_SPACE] > 0)
	{
		count++;
	}
	else
	{
		count = 0;
	}
	if ((count % 10) == 1)
	{
		//ã‚É’e‚ð”ò‚Î‚·
		bulletManager->Shot(&bulletGraphic, pos, VGet(0, -7, 0));
	}
}
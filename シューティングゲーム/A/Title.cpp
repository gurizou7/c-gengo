#include "stdafx.h"
#include"DxLib.h"
#include"Manager.h"
#include"Title.h"
#include"Game.h"
void CTitle::Update()
{
	if (manager->GetKey()[KEY_INPUT_X] >= 1)
	{
		//ゲームにシーン移行
		manager->scene = new CGame(manager);
		delete this;
	}

}

void CTitle::Render()
{
	SetFontSize(50);                             //サイズを20に変更
	SetFontThickness(1);                      //太さを8に変更
	ChangeFont("HGS創英角ﾎﾟｯﾌﾟ体");              //HGS創英角ﾎﾟｯﾌﾟ体に変更
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);//アンチエイリアス＆エッジ付きフォントに変更
	DrawFormatString(60, 150, GetColor(255, 255, 255), "シューティングゲーム");

	
	SetFontSize(30);                        //サイズを20に変更
	SetFontThickness(8);                      //太さを1に変更
	ChangeFont("HGS創英角ﾎﾟｯﾌﾟ体");              //HGS創英角ﾎﾟｯﾌﾟ体に変更
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);//アンチエイリアス＆エッジ付きフォントに変更
	DrawFormatString(120, 300, GetColor(255, 255, 255), "PUSH X KEY");
}
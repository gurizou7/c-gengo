// A.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include"DxLib.h"
#include"Manager.h"
#include"Title.h"
#include"Game.h"
class CGame;

#define KEY_NUM 256
//キーの入力状態を更新する
int gpUpdateKey(char *key) {
	//現在のキーの入力状態を格納する
	char tmpKey[KEY_NUM];
	//全てのキーの入力状態を得る
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i<KEY_NUM; i++) {
		if (tmpKey[i] != 0)
		{//i番のキーコードに対応するキーが押されていたら加算
			key[i]++;
		}
		else
		{//押されていなければ0にする
			key[i] = 0;
		}
	}
	return 0;
}

#define BUFFSIZE 1024
bool Process(char *key) {
	if (ProcessMessage() != 0) return false;
	//画面の裏ページの内容を表ページに反映する
	if (ScreenFlip() != 0) return false;
	//画面を初期化
	if (ClearDrawScreen() != 0) return false;
	//キー取得
	if (gpUpdateKey(key) != 0) return false;
	//エスケープで終了
	if (key[KEY_INPUT_ESCAPE] >= 1) {
	/*	FILE *fp;
		char s[BUFFSIZE];
		errno_t error;
		error = fopen_s(&fp, "SCORE.txt","w");
		if (error != 0){
			fprintf_s(stderr, "failed to open");
		}
		else {
			int cnt1 =
			//fputs("SCORE:", fp);
			//fputs(cnt1[6], fp);
			fprintf(fp, "SCORE:%d", cnt1);
			fclose(fp);
			
		}*/return false;
	}
	return true;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//ウインドウモードに変更
	ChangeWindowMode(TRUE);
	//DXライブラリを初期化する。
	if (DxLib_Init() == -1) return -1;
	//キー取得
	char key[KEY_NUM];
	//描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);
	//管理システムを動的確保
	CManager *manager;
	manager = new CManager(key);
	//タイトルを動的確保
	manager->scene = new CTitle(manager);
	while (Process(key))
	{
		//ゲームループ
		manager->Render();
		manager->Update();
	}
	//後始末
	delete manager;
	//DXライブラリを終了する。
	DxLib_End();

	return 0;
}
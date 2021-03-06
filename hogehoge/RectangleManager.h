#pragma once
#include "MyPG.h"

class RectangleManager
{
public:
	vector<ML::Box2D*>	charaChip;			//キャラクタの素材(変更禁止)
	int					imgSizeW, imgSizeH;	//画像サイズ
	unsigned int		rectNum;			//分割総数

	RectangleManager() :
		imgSizeW(0),
		imgSizeH(0) {}

	//------------------------------------
	//画像の分割用矩形を作成
	//引数：開始位置XY(int, int), 画像の分割数WH(int, int),
	//　　　画像サイズ(int, int)
	void RectCreate(int startX, int startY,
					int width, int height,
					int imageWidth, int imageHeight);

	//------------------------------------
	//画像の分割用矩形を作成(1つだけ)
	//引数：開始位置XY(int, int), 終了位置(int, int)
	void RectOneCreate(int startX, int startY, int endX, int endY);

	//------------------------------------
	//画像の分割データを解放
	void RectErase();
};

//画像の分割管理とアニメーション
class RectAnimManager
{
private:
	RectangleManager*	rectm;			//使用する矩形管理クラス

	unsigned int		animStartNum;	//アニメーションの開始地点
	unsigned int		allAnimNum;		//アニメーション枚数
	POINT				drawPos;		//描画の基準座標

	int					pramiCnt;		//アニメーションがプラスかマイナスかを判定する
	float				animCnt;		//アニメーションカウンタ
	bool				animTurn;		//アニメーションが反転しているか否か

	bool				error;			//何かしらのエラーが発生しました

public:
	//矩形管理クラスのポインタを入れておくれ
	RectAnimManager() :
		rectm(nullptr),
		animStartNum(0),
		allAnimNum(1),
		pramiCnt(0),
		animCnt(0),
		animTurn(false),
		error(true)
	{
		drawPos.x = 0;
		drawPos.y = 0;
	};

	~RectAnimManager() {};

	//--------------------------------------------------------
	//以下使用メソッド

	//------------------------------------
	//矩形の設定
	//引数：矩形管理クラスのアドレス(RectangleManager*)
	void SetRectangle(RectangleManager* rectp);

	//------------------------------------
	//画像表示とアニメーションの準備
	//引数：表示の基準座標(POINT), アニメーションの開始地点番号(unsigned int), 終了地点番号(unsigned int デフォルトで開始地点と同じ)
	//戻り値：準備が完了したか否か(bool)
	bool RectAnimSet(POINT	dPos,
					 int	animStart,
					 int	animEnd = -1);

	//------------------------------------
	//アニメーション
	//引数：アニメーション速度(float)
	void RectAnimation(float animSpd);

	//------------------------------------
	//画像の描画
	//引数：表示座標(ML::Vec2), 画像名(string), 表示色(ML::Color デフォルトで(1, 1, 1, 1))
	void ImageRender(const ML::Vec2&	pos,
					 const string&		imageName,
					 const ML::Color&	color = { 1, 1, 1, 1 });
};
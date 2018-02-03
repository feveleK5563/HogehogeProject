#pragma once
#include "MyPG.h"

//画像の分割管理とアニメーション
class RectangleManager
{
private:
	vector<ML::Box2D*>	charaChip;		//キャラクタの素材

	unsigned int		defImageNum;	//差分用画像番号(1Pカラーと2Pカラーの差分など)
	unsigned int		baseImageNum;	//基準画像番号(アニメーションの基準点)
	unsigned int		rectNum;		//分割総数
	POINT				drawPos;		//描画の基準座標

	unsigned int		animChipNum;	//アニメーション枚数
	float				animCnt;		//アニメーションカウンタ
	bool				animTurn;		//アニメーションが反転しているか否か

public:
	RectangleManager() :
		defImageNum(0),
		baseImageNum(0),
		animChipNum(0),
		animCnt(0),
		animTurn(false)
	{
		drawPos.x = 0;
		drawPos.y = 0;
	};

	~RectangleManager() {};

	//--------------------------------------------------------
	//以下使用メソッド

	//------------------------------------
	//画像の分割用矩形を作成
	//引数：開始位置XY(int, int), 画像の分割数WH(int, int),
	//　　　画像サイズ(int, int デフォルトで32x32)
	void RectCreate(int startX, int startY,
					int width, int height,
					int imageWidth = 32, int imageHeight = 32);

	//------------------------------------
	//画像の分割用矩形を作成(1つだけ)
	//引数：開始位置XY(int, int), 終了位置(int, int)
	void RectOneCreate(int startX, int startY, int endX, int endY);

	//------------------------------------
	//画像の分割データを解放
	void RectErase();

	//------------------------------------
	//画像表示準備
	//引数： 差分用画像番号(unsigned int), 基準画像番号(unsigned int)
	//戻り値：準備が完了したか否か(bool)
	bool RenderSet(unsigned int defNum, unsigned int baseNum);

	//------------------------------------
	//アニメーションの準備
	//引数：基準座標(POINT),アニメーション枚数(unsigned int)
	//戻り値：準備が完了したか否か(bool)
	bool RectAnimSet(POINT			dPos,
					 unsigned int	animChip);

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
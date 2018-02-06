#include "RectangleManager.h"

//-------------------------------------------------------------------
//画像の分割用矩形を作成
//引数：開始位置XY(int, int), 画像の分割数WH(int, int),
//　　　画像サイズ(int, int)
void RectangleManager::RectCreate(int startX,		int startY,
								  int width,		int height,
								  int imageWidth,	int imageHeight)
{
	for (int y = startY; y < startY + height; ++y)
	{
		for (int x = startX; x < startX + width; ++x)
		{
			charaChip.emplace_back(new ML::Box2D(x * imageWidth, y * imageHeight, imageWidth, imageHeight));
		}
	}
	rectNum = charaChip.size();
	imgSizeW = imageWidth;
	imgSizeH = imageHeight;
}

//------------------------------------
//画像の分割用矩形を作成(1つだけ)
//引数：開始位置XY(int, int), 終了位置(int, int)
void RectangleManager::RectOneCreate(int startX, int startY, int endX, int endY)
{
	charaChip.emplace_back(new ML::Box2D(startX, startY, endX, endY));
	rectNum = charaChip.size();
}

//-------------------------------------------------------------------
//画像の分割データを解放
void RectangleManager::RectErase()
{
	int size = charaChip.size();
	for (int i = 0; i < size; ++i)
		delete charaChip[i];
	charaChip.clear();
	charaChip.shrink_to_fit();
	rectNum = 0;
}

//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★

//------------------------------------
//矩形の設定(一番最初に絶対呼んでね！！！)
//引数：矩形管理クラスのアドレス(RectangleManager*)
void RectAnimManager::SetRectangle(RectangleManager* rectp)
{
	rectm = rectp;
	if (rectm != nullptr)
		error = false;
	else
		error = true;
}

//------------------------------------
//画像表示とアニメーションの準備
//引数：表示の基準座標(POINT), アニメーションの開始地点番号(unsigned int), 終了地点番号(unsigned int デフォルトで開始地点と同じ)
//戻り値：準備が完了したか否か(bool)
bool RectAnimManager::RectAnimSet(POINT	dPos,
								   int		animStart,
								   int		animEnd)
{
	if (error)
		return false;

	drawPos = dPos;
	animStartNum = animStart;
	if (animStart < 0			 || animEnd < 0 ||
		animStart > (int)rectm->rectNum || animEnd > (int)rectm->rectNum)
	{
		error = true;
		return false;
	}
	if (animStart <= animEnd)
	{
		pramiCnt = 1;
	}
	else
	{
		pramiCnt = -1;
	}
	allAnimNum = int(fabsf(float(animEnd - animStart))) + 1;

	error = false;
	return true;
}

//-------------------------------------------------------------------
//アニメーション
//引数：アニメーション速度(float)
void RectAnimManager::RectAnimation(float animSpd)
{
	if (error)
		return;

	animCnt += animSpd;
}

//-------------------------------------------------------------------
//画像の描画
//引数：表示座標(ML::Vec2), 画像名(string), 表示色(ML::Color デフォルトで(1, 1, 1, 1))
void RectAnimManager::ImageRender(const ML::Vec2&	pos,
								   const string&	imageName,
								   const ML::Color&	color)
{
	if (error || rectm->charaChip.empty())
		return;

	ML::Box2D draw = { -drawPos.x, -drawPos.y, rectm->imgSizeW, rectm->imgSizeH };
	draw.Offset(pos);
	ML::Box2D src = *rectm->charaChip[animStartNum + (int(animCnt) % allAnimNum)* pramiCnt];
	if (animTurn)
	{
		src.x += src.w;
		src.w *= -1;
	}
	DG::Image_Draw(imageName, draw, src, color);
}
#include "RectangleManager.h"

//-------------------------------------------------------------------
//�摜�̕����p��`���쐬
//�����F�J�n�ʒuXY(int, int), �摜�̕�����WH(int, int)
void RectangleManager::RectCreate(int startX, int startY, int width, int height, int imageWidth, int imageHeight)
{
	for (int y = startY; y < startY + height; ++y)
	{
		for (int x = startX; x < startX + width; ++x)
		{
			charaChip.emplace_back(new ML::Box2D(x * imageWidth, y * imageHeight, imageWidth, imageHeight));
		}
	}
	rectNum = charaChip.size;
}

//------------------------------------
//�摜�̕����p��`���쐬(1����)
//�����F�J�n�ʒuXY(int, int), �I���ʒu(int, int)
void RectangleManager::RectOneCreate(int startX, int startY, int endX, int endY)
{
	charaChip.emplace_back(new ML::Box2D(startX, startY, endX, endY));
	rectNum = charaChip.size;
}

//-------------------------------------------------------------------
//�摜�̕����f�[�^�����
void RectangleManager::RectErase()
{
	int size = charaChip.size();
	for (int i = 0; i < size; ++i)
		delete charaChip[i];
	charaChip.clear();
	charaChip.shrink_to_fit();
}

//-------------------------------------------------------------------
//�A�j���[�V��������
//�����F
bool RectangleManager::RectAnimSet(unsigned int animChip, unsigned int baseNum, unsigned int defNum)
{
	if (animChip > rectNum ||
		baseNum > rectNum ||
		defNum > rectNum)
		return false;

	animChipNum = animChip;
	baseImageNum = baseNum;
	defImageNum = defNum;
}

//-------------------------------------------------------------------
//�A�j���[�V����
//�����F�A�j���[�V�������x(float)
void RectangleManager::RectAnimation(float animSpeed)
{
	animCnt += animSpeed;
}

//-------------------------------------------------------------------
//�摜�̕`��
//�����F�\�����W(ML::Vec2), �摜��(string), �\���F(ML::Color �f�t�H���g��(1, 1, 1, 1))
void RectangleManager::ImageRender(const ML::Vec2& pos, const string& imageName, const ML::Color& color)
{
	if (charaChip.empty())
		return;

	ML::Box2D draw = { -drawPos.x, -drawPos.y, 32, 32 };
	draw.Offset(pos);
	ML::Box2D src = *charaChip[(defImageNum + baseImageNum + int(animCnt)) % animChipNum];
	if (animTurn)
	{
		src.x += src.w;
		src.w *= -1;
	}
	DG::Image_Draw(imageName, draw, src, color);
}
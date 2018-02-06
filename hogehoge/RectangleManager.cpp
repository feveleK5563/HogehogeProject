#include "RectangleManager.h"

//-------------------------------------------------------------------
//�摜�̕����p��`���쐬
//�����F�J�n�ʒuXY(int, int), �摜�̕�����WH(int, int),
//�@�@�@�摜�T�C�Y(int, int)
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
//�摜�̕����p��`���쐬(1����)
//�����F�J�n�ʒuXY(int, int), �I���ʒu(int, int)
void RectangleManager::RectOneCreate(int startX, int startY, int endX, int endY)
{
	charaChip.emplace_back(new ML::Box2D(startX, startY, endX, endY));
	rectNum = charaChip.size();
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
	rectNum = 0;
}

//����������������������������������������������������������������������������������������������

//------------------------------------
//��`�̐ݒ�(��ԍŏ��ɐ�ΌĂ�łˁI�I�I)
//�����F��`�Ǘ��N���X�̃A�h���X(RectangleManager*)
void RectAnimManager::SetRectangle(RectangleManager* rectp)
{
	rectm = rectp;
	if (rectm != nullptr)
		error = false;
	else
		error = true;
}

//------------------------------------
//�摜�\���ƃA�j���[�V�����̏���
//�����F�\���̊���W(POINT), �A�j���[�V�����̊J�n�n�_�ԍ�(unsigned int), �I���n�_�ԍ�(unsigned int �f�t�H���g�ŊJ�n�n�_�Ɠ���)
//�߂�l�F�����������������ۂ�(bool)
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
//�A�j���[�V����
//�����F�A�j���[�V�������x(float)
void RectAnimManager::RectAnimation(float animSpd)
{
	if (error)
		return;

	animCnt += animSpd;
}

//-------------------------------------------------------------------
//�摜�̕`��
//�����F�\�����W(ML::Vec2), �摜��(string), �\���F(ML::Color �f�t�H���g��(1, 1, 1, 1))
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
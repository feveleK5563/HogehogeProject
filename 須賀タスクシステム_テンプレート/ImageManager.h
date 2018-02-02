#pragma once
#include "MyPG.h"

//�摜�̕����Ǘ��ƃA�j���[�V����
class RectangleManager
{
private:
	vector<ML::Box2D*>	charaChip;		//�L�����N�^�̑f��
	int					defImageNum;	//�����p�摜�ԍ�(1P�J���[��2P�J���[�̍����Ȃ�)
	int					baseImageNum;	//��摜�ԍ�(�A�j���[�V�����̊�_)
	int					rectNum;		//��������
	POINT				drawPos;		//�`��̊���W
	float				animCnt;		//�A�j���[�V�����J�E���^
	bool				animTurn;		//�A�j���[�V���������]���Ă��邩�ۂ�

public:
	RectangleManager() :
		defImageNum(0),
		baseImageNum(0),
		animCnt(0),
		animTurn(false)
	{
		drawPos.x = 0;
		drawPos.y = 0;
	};

	~RectangleManager() {};

	//--------------------------------------------------------
	//�ȉ��g�p���\�b�h

	//------------------------------------
	//�摜�̕���
	//�����F�J�n�ʒuXY(int, int), �摜�̕�����WH(int, int), �摜�T�C�Y(int, int �f�t�H���g��32x32)
	void ImageCreate(int startX, int startY, int width, int height, int imageWidth = 32, int imageHeight = 32);

	//------------------------------------
	//�摜�̕���(1����)
	//�����F�J�n�ʒuXY(int, int), �I���ʒu(int, int)
	void ImageOneCreate(int startX, int startY, int endX, int endY);

	//------------------------------------
	//�摜�̕�������
	void ImageErase();

	//------------------------------------
	//�A�j���[�V����
	//�����F�A�j���[�V�������x(float)


	//------------------------------------
	//�摜�̕`��
	//�����F�\�����W(ML::Vec2), �摜��(string), �\���F(ML::Color �f�t�H���g��(1, 1, 1, 1))
	void ImageRender(const ML::Vec2& pos, const string& imageName, const ML::Color& color = { 1, 1, 1, 1 });
};
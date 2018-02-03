#pragma once
#include "MyPG.h"

//�摜�̕����Ǘ��ƃA�j���[�V����
class RectangleManager
{
private:
	vector<ML::Box2D*>	charaChip;		//�L�����N�^�̑f��

	unsigned int		defImageNum;	//�����p�摜�ԍ�(1P�J���[��2P�J���[�̍����Ȃ�)
	unsigned int		baseImageNum;	//��摜�ԍ�(�A�j���[�V�����̊�_)
	unsigned int		rectNum;		//��������
	POINT				drawPos;		//�`��̊���W

	unsigned int		animChipNum;	//�A�j���[�V��������
	float				animCnt;		//�A�j���[�V�����J�E���^
	bool				animTurn;		//�A�j���[�V���������]���Ă��邩�ۂ�

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
	//�ȉ��g�p���\�b�h

	//------------------------------------
	//�摜�̕����p��`���쐬
	//�����F�J�n�ʒuXY(int, int), �摜�̕�����WH(int, int),
	//�@�@�@�摜�T�C�Y(int, int �f�t�H���g��32x32)
	void RectCreate(int startX, int startY,
					int width, int height,
					int imageWidth = 32, int imageHeight = 32);

	//------------------------------------
	//�摜�̕����p��`���쐬(1����)
	//�����F�J�n�ʒuXY(int, int), �I���ʒu(int, int)
	void RectOneCreate(int startX, int startY, int endX, int endY);

	//------------------------------------
	//�摜�̕����f�[�^�����
	void RectErase();

	//------------------------------------
	//�摜�\������
	//�����F �����p�摜�ԍ�(unsigned int), ��摜�ԍ�(unsigned int)
	//�߂�l�F�����������������ۂ�(bool)
	bool RenderSet(unsigned int defNum, unsigned int baseNum);

	//------------------------------------
	//�A�j���[�V�����̏���
	//�����F����W(POINT),�A�j���[�V��������(unsigned int)
	//�߂�l�F�����������������ۂ�(bool)
	bool RectAnimSet(POINT			dPos,
					 unsigned int	animChip);

	//------------------------------------
	//�A�j���[�V����
	//�����F�A�j���[�V�������x(float)
	void RectAnimation(float animSpd);

	//------------------------------------
	//�摜�̕`��
	//�����F�\�����W(ML::Vec2), �摜��(string), �\���F(ML::Color �f�t�H���g��(1, 1, 1, 1))
	void ImageRender(const ML::Vec2&	pos,
					 const string&		imageName,
					 const ML::Color&	color = { 1, 1, 1, 1 });
};
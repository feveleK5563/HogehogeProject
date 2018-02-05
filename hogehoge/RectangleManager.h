#pragma once
#include "MyPG.h"

//�摜�̕����Ǘ��ƃA�j���[�V����
class RectangleManager
{
private:
	vector<ML::Box2D*>	charaChip;		//�L�����N�^�̑f��
	unsigned int		rectNum;		//��������

	unsigned int		animStartNum;	//�A�j���[�V�����̊J�n�n�_
	unsigned int		allAnimNum;		//�A�j���[�V��������
	POINT				drawPos;		//�`��̊���W

	int					pramiCnt;		//�A�j���[�V�������v���X���}�C�i�X���𔻒肷��
	float				animCnt;		//�A�j���[�V�����J�E���^
	bool				animTurn;		//�A�j���[�V���������]���Ă��邩�ۂ�

	bool				error;			//��������̃G���[���������܂���

public:
	RectangleManager() :
		animStartNum(0),
		allAnimNum(1),
		pramiCnt(0),
		animCnt(0),
		animTurn(false),
		error(false)
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
	//�摜�\���ƃA�j���[�V�����̏���
	//�����F�\���̊���W(POINT), �A�j���[�V�����̊J�n�n�_�ԍ�(unsigned int), �I���n�_�ԍ�(unsigned int �f�t�H���g�ŊJ�n�n�_�Ɠ���)
	//�߂�l�F�����������������ۂ�(bool)
	bool RectAnimSet(POINT	dPos,
					 int	animStart,
					 int	animEnd = -1);

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
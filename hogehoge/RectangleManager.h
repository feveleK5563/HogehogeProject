#pragma once
#include "MyPG.h"

class RectangleManager
{
public:
	vector<ML::Box2D*>	charaChip;			//�L�����N�^�̑f��(�ύX�֎~)
	int					imgSizeW, imgSizeH;	//�摜�T�C�Y
	unsigned int		rectNum;			//��������

	RectangleManager() :
		imgSizeW(0),
		imgSizeH(0) {}

	//------------------------------------
	//�摜�̕����p��`���쐬
	//�����F�J�n�ʒuXY(int, int), �摜�̕�����WH(int, int),
	//�@�@�@�摜�T�C�Y(int, int)
	void RectCreate(int startX, int startY,
					int width, int height,
					int imageWidth, int imageHeight);

	//------------------------------------
	//�摜�̕����p��`���쐬(1����)
	//�����F�J�n�ʒuXY(int, int), �I���ʒu(int, int)
	void RectOneCreate(int startX, int startY, int endX, int endY);

	//------------------------------------
	//�摜�̕����f�[�^�����
	void RectErase();
};

//�摜�̕����Ǘ��ƃA�j���[�V����
class RectAnimManager
{
private:
	RectangleManager*	rectm;			//�g�p�����`�Ǘ��N���X

	unsigned int		animStartNum;	//�A�j���[�V�����̊J�n�n�_
	unsigned int		allAnimNum;		//�A�j���[�V��������
	POINT				drawPos;		//�`��̊���W

	int					pramiCnt;		//�A�j���[�V�������v���X���}�C�i�X���𔻒肷��
	float				animCnt;		//�A�j���[�V�����J�E���^
	bool				animTurn;		//�A�j���[�V���������]���Ă��邩�ۂ�

	bool				error;			//��������̃G���[���������܂���

public:
	//��`�Ǘ��N���X�̃|�C���^�����Ă�����
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
	//�ȉ��g�p���\�b�h

	//------------------------------------
	//��`�̐ݒ�
	//�����F��`�Ǘ��N���X�̃A�h���X(RectangleManager*)
	void SetRectangle(RectangleManager* rectp);

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
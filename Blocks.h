#pragma once
#include "Catch.h"
#include "Ball.h"

enum Hit {
	horizontal_blow, //������ ���� �� �����������
	vertical_blow,  //������ ���� �� ���������
	missed   //������ �� �����
};

enum crushability {
	yes, //���������� �����
	no
};

enum DirectionBLock {
	straight, //�������� ����� �����
	back //�������� ����� �������
};

//catcher_more, //������ ������ �����
//catcher_less, //������ ������ �����
//plus_life, //���� �����
//speed_the_ball, //�������� ���
//slow_the_ball, // ��������� ���
//ball_increase, // ��������� ���
//ball_stick, // ���������� ����
//trampoline // �����

class Bonus {
public:
	Bonus(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Draw(void);
	void BonusMove(int d);
	virtual void Realise_bonus(void);
	virtual void Draw_bonus(void);
	bool move_bonus_flag;
	bool destroy_flag;
	virtual ~Bonus();

	int x1;// ����� �������
	int y1;
	int x2;//������ ������
	int y2;
};

class Bonus_catcher_more : public Bonus {
public:
	Bonus_catcher_more(Catch * catcher, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int step_cather = 20);
	void Realise_bonus(void);
	void Draw_bonus(void);
	~Bonus_catcher_more();
	Catch * catcher;
	int step_catcher;
	labcolor_t color;
};

class Bonus_catcher_less : public Bonus {
public:
	Bonus_catcher_less(Catch * catcher, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int step_cather = 20);
	void Realise_bonus(void);
	void Draw_bonus(void);
	~Bonus_catcher_less();
	Catch * catcher;
	int step_catcher;
	labcolor_t color;
};


class Bonus_plus_life : public Bonus {
public:
	Bonus_plus_life(Catch * catcher, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Realise_bonus(void);
	void Draw_bonus(void);
	~Bonus_plus_life();
	Catch * catcher;
	labcolor_t color;
};

class Bonus_speed_ball : public Bonus {
public:
	Bonus_speed_ball(Ball * ball1, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Realise_bonus(void);
	void Draw_bonus(void);
	~Bonus_speed_ball();
	Ball * ball1;
	labcolor_t color;
};

class Bonus_slow_ball : public Bonus {
public:
	Bonus_slow_ball(Ball * ball1, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Realise_bonus(void);
	void Draw_bonus(void);
	~Bonus_slow_ball();
	Ball * ball1;
	labcolor_t color;
};

class Bonus_ball_increase : public Bonus {
public:
	Bonus_ball_increase(Ball * ball1, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int delta_rad = 6);
	void Realise_bonus(void);
	void Draw_bonus(void);
	~Bonus_ball_increase();
	Ball * ball1;
	int delta_rad;
	labcolor_t color;
};


class Bonus_ball_stick : public Bonus {
public:
	Bonus_ball_stick(Ball * ball1, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int sticks = 3);
	void Realise_bonus(void);
	void Draw_bonus(void);
	~Bonus_ball_stick();
	Ball * ball1;
	int sticks;
	labcolor_t color;
};

class Bonus_trampline : public Bonus {
public:
	Bonus_trampline(Ball * ball1, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Realise_bonus(void);
	void Draw_bonus(void);
	~Bonus_trampline();
	Ball * ball1;
	labcolor_t color;
};



class Block {
public:
	Block(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	virtual void Draw(void);
	void ChangeLifeCount(int count);
	void DecCountLife(void);
	int GetLifeCount(void);
	void ChangeSmash(crushability smash);
	bool GetSmash(void);
	bool GetMobile_flag(void);
	void ChangeMobile(bool flag);
	void BlockMove(int d);
	bool GetSide(void);
	void ChangeSide(DirectionBLock a);
	void ChangeBonus(bool bonus);
	bool GetBonus(void);
	bool CheckActiveBonuse(void);
	virtual ~Block(void);

	int flag_destroy; //��������(��/���)
	int x1;// ����� �������
	int y1;
	int x2;//������ ������
	int y2;
	int life_count; //���������� ������
	bool mobile; //�����������(��/���)
	crushability smash; //����������(��/���)
	DirectionBLock side;//����������� �������� ���������� �����
	bool bonus_flag;
	Bonus * bonus_block;
	int step_block;
};

class Block_three : public Block {
public:
	Block_three(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Draw(void);
	~Block_three();
	labcolor_t color_block;
};

class Block_one : public Block {
public:
	Block_one(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Draw(void);
	~Block_one();
	labcolor_t color_block;
};

class Block_dinamic : public Block {
public:
	Block_dinamic(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Draw(void);
	~Block_dinamic();
	labcolor_t color_block;
};

class Block_strong : public Block {
public:
	Block_strong(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);
	void Draw(void);
	~Block_strong();
	labcolor_t color_block;
};
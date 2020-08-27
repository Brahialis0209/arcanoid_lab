
#include "Blocks_functions.h"
// бонус

Bonus::Bonus(int x1, int y1, int x2, int y2) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

Bonus::~Bonus() {}

void Bonus::Draw(void) {
	LabDrawRectangle(x1, y1, x2, y2);
}

void Bonus::BonusMove(int d) {
	this->y1 = this->y1 + d;
	this->y2 = this->y2 + d;
}

//увеличение ракетки
Bonus_catcher_more::Bonus_catcher_more(Catch * catcher, int x1, int y1, int x2, int y2, int step_catcher)
	: Bonus(x1, y1, x2, y2)
{
	this->catcher = catcher;
	this->step_catcher = step_catcher;
	this->color = LABCOLOR_DARK_BLUE;
}

void Bonus_catcher_more::Draw_bonus(void) {
	LabSetColor(color);
	this->Draw();
	LabSetColor(LABCOLOR_WHITE);
}

Bonus_catcher_more::~Bonus_catcher_more() {}

void Bonus_catcher_more::Realise_bonus(void) {
	catcher->Increase(step_catcher);
	cout << "Catcher increases=) !!!" << endl;
	this->destroy_flag = 1;
	this->move_bonus_flag = 0;
}



//уменьшение ракетки
Bonus_catcher_less::Bonus_catcher_less(Catch * catcher, int x1, int y1, int x2, int y2, int step_catcher)
	: Bonus(x1, y1, x2, y2)
{
	this->catcher = catcher;
	this->step_catcher = step_catcher;
	this->color = LABCOLOR_DARK_RED;
}

void Bonus_catcher_less::Draw_bonus(void) {
	LabSetColor(color);
	this->Draw();
	LabSetColor(LABCOLOR_WHITE);
}

Bonus_catcher_less::~Bonus_catcher_less() {}

void Bonus_catcher_less::Realise_bonus(void) {
	catcher->Decrease(step_catcher);
	cout << "Catcher decreases=( !!!" << endl;
	this->destroy_flag = 1;
	this->move_bonus_flag = 0;
}


//+ жизнь
Bonus_plus_life::Bonus_plus_life(Catch * catcher, int x1, int y1, int x2, int y2)
	: Bonus(x1, y1, x2, y2)
{
	this->catcher = catcher;
	this->color = LABCOLOR_DARK_BLUE;
}

void Bonus_plus_life::Draw_bonus(void) {
	LabSetColor(color);
	this->Draw();
	LabSetColor(LABCOLOR_WHITE);
}

Bonus_plus_life::~Bonus_plus_life() {}

void Bonus_plus_life::Realise_bonus(void) {
	catcher->Inc_life();
	cout << "You have received one life, you dull them with you:" << catcher->life_count << endl;
	this->destroy_flag = 1;
	this->move_bonus_flag = 0;
}


//+ скорость м€ча
Bonus_speed_ball::Bonus_speed_ball(Ball * ball1, int x1, int y1, int x2, int y2)
	: Bonus(x1, y1, x2, y2)
{
	this->ball1 = ball1;
	this->color = LABCOLOR_DARK_RED;
}

void Bonus_speed_ball::Draw_bonus(void) {
	LabSetColor(color);
	this->Draw();
	LabSetColor(LABCOLOR_WHITE);
}

Bonus_speed_ball::~Bonus_speed_ball() {}

void Bonus_speed_ball::Realise_bonus(void) {
	cout << "The ball sped up!Pay attention!" << endl;
	ball1->delay -= 10;
	ball1->step_ball += 1;
	this->destroy_flag = 1;
	this->move_bonus_flag = 0;
}


//- скорость м€ча
Bonus_slow_ball::Bonus_slow_ball(Ball * ball1, int x1, int y1, int x2, int y2)
	: Bonus(x1, y1, x2, y2)
{
	this->ball1 = ball1;
	this->color = LABCOLOR_DARK_BLUE;
}

void Bonus_slow_ball::Draw_bonus(void) {
	LabSetColor(color);
	this->Draw();
	LabSetColor(LABCOLOR_WHITE);
}

Bonus_slow_ball::~Bonus_slow_ball() {}

void Bonus_slow_ball::Realise_bonus(void) {
	cout << "The ball slowed down!exhale!" << endl;
	ball1->delay += 10;
	ball1->step_ball -= 1;
	this->destroy_flag = 1;
	this->move_bonus_flag = 0;
}


//+ –азмер м€ча
Bonus_ball_increase::Bonus_ball_increase(Ball * ball1, int x1, int y1, int x2, int y2, int delta_rad)
	: Bonus(x1, y1, x2, y2)
{
	this->ball1 = ball1;
	this->color = LABCOLOR_DARK_BLUE;
	this->delta_rad = delta_rad;
}

void Bonus_ball_increase::Draw_bonus(void) {
	LabSetColor(color);
	this->Draw();
	LabSetColor(LABCOLOR_WHITE);
}

Bonus_ball_increase::~Bonus_ball_increase() {}

void Bonus_ball_increase::Realise_bonus(void) {
	time(&ball1->start);
	ball1->grow_flag = 1;
	ball1->In_r(delta_rad);
	cout << "The BALL is increased by 15 seconds!!1" << endl;
	this->destroy_flag = 1;
	this->move_bonus_flag = 0;
}

//ѕрилипание м€ча
Bonus_ball_stick::Bonus_ball_stick(Ball * ball1, int x1, int y1, int x2, int y2, int sticks)
	: Bonus(x1, y1, x2, y2)
{
	this->ball1 = ball1;
	this->color = LABCOLOR_DARK_BLUE;
	this->sticks = sticks;
}

void Bonus_ball_stick::Draw_bonus(void) {
	LabSetColor(color);
	this->Draw();
	LabSetColor(LABCOLOR_WHITE);
}

Bonus_ball_stick::~Bonus_ball_stick() {}

void Bonus_ball_stick::Realise_bonus(void) {
	ball1->In_stick(sticks);
	cout << "The ball will stick 3 times" << endl;
	this->destroy_flag = 1;
	this->move_bonus_flag = 0;
}

//“рамплин
Bonus_trampline::Bonus_trampline(Ball * ball1, int x1, int y1, int x2, int y2)
	: Bonus(x1, y1, x2, y2)
{
	this->ball1 = ball1;
	this->color = LABCOLOR_DARK_BLUE;
}

void Bonus_trampline::Draw_bonus(void) {
	LabSetColor(color);
	this->Draw();
	LabSetColor(LABCOLOR_WHITE);
}

Bonus_trampline::~Bonus_trampline() {}

void Bonus_trampline::Realise_bonus(void) {
	ball1->trampoline_flag = 1;
	cout << "The ball rebound when falling! you got a trampoline!" << endl;
	this->destroy_flag = 1;
	this->move_bonus_flag = 0;
}


void Bonus::Realise_bonus(void) {}
void Bonus::Draw_bonus(void) {}





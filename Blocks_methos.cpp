#include "Blocks_functions.h"

double radian(void) {
	double pi = 3.14159265359;
	double radian = pi / 180;
	return radian;
}

//блок
Block::Block(int x1, int y1, int x2, int y2) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->step_block = 3;
}
void Block::Draw(void) {}

void Block::ChangeLifeCount(int count) {
	life_count = count;
}

//if (block->flag_destroy) {
//	if (block->bonus_flag && block->bonus_block->move_bonus_flag && !block->bonus_block->destroy_flag)

bool Block::CheckActiveBonuse(void) {
	if (this->flag_destroy) {
		if (this->bonus_flag && this->bonus_block->move_bonus_flag && !this->bonus_block->destroy_flag)
			return true;
	}
	return false;
}

void Block::DecCountLife(void) {
	this->life_count--;
}
int Block::GetLifeCount(void) {
	return life_count;
}
void Block::ChangeSmash(crushability smash) {
	this->smash = smash;
}
bool Block::GetSmash(void) {
	if (smash == yes) return true;
	else return false;
}

bool Block::GetMobile_flag(void) {
	return mobile;
}

void Block::ChangeMobile(bool flag) {
	this->mobile = flag;
}

void Block::BlockMove(int d) {
	this->x1 = this->x1 + d;
	this->x2 = this->x2 + d;
}

bool Block::GetSide(void) {
	return side;
}

void Block::ChangeSide(DirectionBLock a) {
	this->side = a;
}

void Block::ChangeBonus(bool bonus) {
	this->bonus_flag = bonus;
	if (bonus) {
		this->bonus_block->move_bonus_flag = 0;
		this->bonus_block->destroy_flag = 0;
	}
}

bool Block::GetBonus(void) {
	return bonus_flag;
}

Block:: ~Block(void) {
	delete bonus_block;
}


//для конкретных блоков!
//3 жизни обычный блок
Block_three::Block_three(int x1, int y1, int x2, int y2)
	: Block(x1, y1, x2, y2) {
	this->color_block = LABCOLOR_DARK_GREY;
	this->ChangeLifeCount(3);
	this->ChangeSmash(yes);
	this->ChangeBonus(0);
	this->bonus_flag = 0;
	this->ChangeMobile(0);
}
void Block_three::Draw(void) {
	if (!this->flag_destroy) {
		if (this->GetLifeCount() == 3) {
			LabSetColor(color_block);
			LabDrawRectangle(x1, y1, x2, y2);
		}
		else if (this->GetLifeCount() == 2) {
			this->color_block = LABCOLOR_LIGHT_GREY;
			LabSetColor(color_block);
			LabDrawRectangle(x1, y1, x2, y2);
		}
		else if (this->GetLifeCount() == 1) {
			this->color_block = LABCOLOR_MAGENTA;
			LabSetColor(color_block);
			LabDrawRectangle(x1, y1, x2, y2);
		}
	}
}
Block_three::~Block_three() {}



//1 жизнь обычный блок
Block_one::Block_one(int x1, int y1, int x2, int y2)
	: Block(x1, y1, x2, y2) {
	this->color_block = LABCOLOR_MAGENTA;
	this->ChangeLifeCount(1);
	this->ChangeSmash(yes);
	this->ChangeBonus(0);
	this->bonus_flag = 0;
	this->ChangeMobile(0);
}
void Block_one::Draw(void) {
	if (!this->flag_destroy) {
		LabSetColor(color_block);
		LabDrawRectangle(x1, y1, x2, y2);
	}
}
Block_one::~Block_one() {}


//дин блок с 2 жизнями
Block_dinamic::Block_dinamic(int x1, int y1, int x2, int y2)
	: Block(x1, y1, x2, y2) {
	this->color_block = LABCOLOR_LIGHT_GREY;
	this->ChangeLifeCount(2);
	this->ChangeSmash(yes);
	this->ChangeBonus(0);
	this->bonus_flag = 0;
	this->ChangeMobile(1);
	this->ChangeSide(straight);
}
void Block_dinamic::Draw(void) {
	if (!this->flag_destroy) {
		if (this->GetLifeCount() == 2) {
			LabSetColor(color_block);
			LabDrawRectangle(x1, y1, x2, y2);
		}
		else if (this->GetLifeCount() == 1) {
			this->color_block = LABCOLOR_MAGENTA;
			LabSetColor(color_block);
			LabDrawRectangle(x1, y1, x2, y2);
		}
	}
}
Block_dinamic::~Block_dinamic() {}


//неразрушимый
Block_strong::Block_strong(int x1, int y1, int x2, int y2)
	: Block(x1, y1, x2, y2) {
	this->color_block = LABCOLOR_YELLOW;
	this->ChangeLifeCount(3);
	this->ChangeSmash(no);
	this->ChangeBonus(0);
	this->bonus_flag = 0;
	this->ChangeMobile(0);
}
void Block_strong::Draw(void) {
	LabSetColor(color_block);
	LabDrawRectangle(x1, y1, x2, y2);
}
Block_strong::~Block_strong() {}
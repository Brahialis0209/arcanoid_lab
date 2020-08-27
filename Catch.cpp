#include "Catch.h"
#include "Headers.h"

Catch::Catch(int x1, int y1, int x2, int y2) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void Catch::Draw(void) {
	LabSetColor(LABCOLOR_DARK_RED);
	LabDrawRectangle(x1, y1, x2, y2);
	LabSetColor(LABCOLOR_WHITE);
}

void Catch::Increase(int step) {
	x1 = x1 - step;
	x2 = x2 + step;
}

void Catch::Decrease(int step) {
	x1 = x1 + step;
	x2 = x2 - step;
}

void Catch::Dec_life(void) {
	this->life_count -= 1;
}

void Catch::Inc_life(void) {
	this->life_count += 1;
}

void Catch::Move(int d_x) {
	this->x1 = this->x1 + d_x;
	this->x2 = this->x2 + d_x;
}
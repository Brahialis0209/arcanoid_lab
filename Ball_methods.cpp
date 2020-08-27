#pragma once
#include "Ball.h"

Ball::Ball(int x, int y, int r, int angle, int delay = 20, int step_ball = 7) {
	this->r = r;
	this->x = x;
	this->y = y;
	this->angle = angle;
	this->stick_count = 0;
	this->trampoline_flag = 0;
	this->grow_flag = 0;
	this->start_move_flag = 0;
	this->step_ball = step_ball;
	this->delay = delay;
}

void Ball::Move(void) {

	this->x = (int)(this->x + (step_ball * cos(angle * radian())));
	this->y = (int)(this->y - (step_ball * sin(angle * radian())));
}

void Ball::Draw(void) {
	LabSetColor(LABCOLOR_GREEN);
	LabDrawCircle(x, y, r);
	LabSetColor(LABCOLOR_WHITE);
}

void Ball::In_r(int delta_rad) {
	this->r += delta_rad;

}

void Ball::Dec_r(int delta_rad) {
	this->r -= delta_rad;
}

void Ball::In_stick(int sticks) {
	this->stick_count = sticks;
}


void Ball::Dec_stick(void) {
	this->stick_count--;
}


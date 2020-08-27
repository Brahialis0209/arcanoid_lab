#pragma once
#include "Headers.h"
class Ball {
public:
	Ball(int x, int y, int r, int angle,int delay, int step_ball);

	void Move(void);

	void Draw(void);
	void In_r(int delta_rad);
	void Dec_r(int delta_rad);

	void In_stick(int sticks);
	void Dec_stick(void);

	int x;
	int y;
	int r;
	double angle;
	bool start_move_flag;
	bool grow_flag;
	time_t start;
	time_t end;
	int stick_count;
	bool trampoline_flag;
	int delay;
	int step_ball;
};
#pragma once
//#include "Blocks_functions.h"
class Catch {
public:

	Catch(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

	void Draw(void);

	void Increase(int step);

	void Decrease(int step);

	void Dec_life(void);

	void Inc_life(void);

	void Move(int d_x);

	int x1;
	int y1;
	int x2;
	int y2;
	int life_count;
};

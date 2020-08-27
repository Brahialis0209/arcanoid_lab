#pragma once
#include "Headers.h"
#include "Blocks.h"
#include "Catch.h"
#include "Ball.h"


void Buildingblocks(vector<vector <Block*>> & blocks, int row_size, int column_size, Catch * catcher, Ball * ball1);
void BlockDown(vector<vector <Block*>> & blocks, int row_size, int column_size, const Catch & catcher);
void BlockRun(vector<vector <Block*>> & blocks, int  row_size, int column_size);
Hit ChekBlockDestroy(Ball & ball1, vector<vector <Block*>> & blocks, int * personal_account, int row_size, int column_size);
void DrawBlocks(vector<vector <Block*>> & blocks, int row_size, int column_size);
double radian(void);
void RealeseDownBonus(Block * block, const Catch & catcher);
bool CheckCatchBonus(int x_buf1, int x_buf2, int y_buf1, const Catch & catcher);
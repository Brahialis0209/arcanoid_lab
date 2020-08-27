#pragma once
#include "Headers.h"
#include "Ball.h"
#include "Blocks.h"
#include "Catch.h"

bool Check_ball_stick(Ball & ball1, Catch & catcher);
void Check_ball_grow(Ball & ball1);
bool CheckNewedge(const Ball & ball1, int step_ball);
void MoveBonuses(vector<vector <Block*>> & blocks, int step_bonus, int row_size, int  column_size);
void DrawBOnuses(vector<vector <Block*>> & blocks, int row_size, int  column_size);	
bool CheckLeftedge(const Ball & ball1, int step_ball);
bool CheckRightedge(const Ball & ball1, int step_ball);
bool CheckUp(const Ball & ball1, int step_ball);
bool CheckEndgame(const vector<vector <Block*>> & blocks, int row_size, int column_size);
bool CheckDeparture(Catch & catcher, Ball & ball1);
bool CathcerDown(const Catch & catcher, const Ball & ball1);




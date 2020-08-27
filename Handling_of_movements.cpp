#include "Handling_of_movements.h"

bool CheckNewedge(const Ball & ball1, int step_ball) {
	int width = LabGetWidth();
	int height = LabGetHeight();
	for (int circle_angle = 0; circle_angle <= 360; circle_angle += 3) {
		double x_buf = (ball1.x + ball1.r * cos(radian() * circle_angle));
		double y_buf = (ball1.y - ball1.r * sin(radian() * circle_angle));
		if (x_buf <= 0 || x_buf >= width || y_buf <= 0 || y_buf >= height) {
			return true;
		}
	}
	return false;
}

void Check_ball_grow(Ball & ball1) {
	if (ball1.grow_flag) {
		time(&ball1.end);
		int delta_rad = 6;
		double seconds = difftime(ball1.end, ball1.start);
		if (seconds > 15) {
			ball1.Dec_r(delta_rad);
			ball1.grow_flag = 0;
			cout << "The ball is reduced!!!1" << endl;
		}
	}
}

bool Check_ball_stick(Ball & ball1, Catch & catcher) {
	if (ball1.stick_count != 0 && CathcerDown(catcher, ball1)) { //флаг для прилипаний не ноль и задела ракетку
		ball1.y = catcher.y1 - ball1.r;
		return true;
	}
	return false;
}

void DrawBOnuses(vector<vector <Block*>> & blocks, int row_size, int  column_size) {
	for (int j = 0; j < row_size; j++) {
		for (int i = 0; i < column_size; i++) {
				if(blocks[j][i]->CheckActiveBonuse()){
					blocks[j][i]->bonus_block->Draw_bonus();
				}
		}
	}
}

void MoveBonuses(vector<vector <Block*>> & blocks, int step_bonus, int row_size, int  column_size) {
	for (int j = 0; j < row_size; j++) {
		for (int i = 0; i < column_size; i++) {
			if (blocks[j][i]->flag_destroy) {
				if (blocks[j][i]->bonus_flag && blocks[j][i]->bonus_block->move_bonus_flag && !blocks[j][i]->bonus_block->destroy_flag) {
					blocks[j][i]->bonus_block->BonusMove(step_bonus);
				}
			}
		}
	}
}

bool CathcerDown(const Catch & catcher, const Ball & ball1) {
	for (int circle_angle = 0; circle_angle <= 360; circle_angle += 3) {
		double x_buf = (ball1.x + (ball1.r) * cos(radian() * circle_angle));
		double y_buf = (ball1.y - (ball1.r) * sin(radian() * circle_angle));
		if (x_buf >= catcher.x1 && x_buf <= catcher.x2) {
			if (y_buf >= catcher.y1 && y_buf <= catcher.y2) {
				return true;
			}
		}
	}
	return false;
}

bool CheckDeparture(Catch & catcher, Ball & ball1) {
	int height = LabGetHeight();
	for (int circle_angle = 1; circle_angle <= 360; circle_angle += 3) {
		int x_buf = (int)(ball1.x + ball1.r * cos(radian() * circle_angle));
		int y_buf = (int)(ball1.y - ball1.r * sin(radian() * circle_angle));
		if (x_buf < catcher.x1 || x_buf > catcher.x2) {
			if (y_buf >= catcher.y2) {
				ball1.y = height - ball1.r;
				return true;
			}
		}
	}
	return false;
}


bool CheckEndgame(const vector<vector <Block*>> & blocks, int row_size, int column_size) {
	int flag = 0;
	for (int j = 0; j < row_size; j++) {
		for (int i = 0; i < column_size; i++) {
			if (blocks[j][i]->flag_destroy == 0 && blocks[j][i]->GetSmash()) {
				flag = 1;
			}
		}
	}
	if (flag) return false;
	else return true;
}

bool CheckUp(const Ball & ball1, int step_ball) {
	int width = LabGetWidth();
	int height = LabGetHeight();
	for (int circle_angle = 0; circle_angle <= 360; circle_angle += 3) {
		if ((ball1.y - ball1.r * sin(radian() * circle_angle) <= 0)) {
			return true;
		}
	}
	return false;
}
bool CheckRightedge(const Ball & ball1, int step_ball) {
	int width = LabGetWidth();
	int height = LabGetHeight();
	for (int circle_angle = 0; circle_angle <= 360; circle_angle += 3) {
		if (ball1.x + ball1.r * cos(radian() * circle_angle) >= width) {
			return true;
		}
	}
	return false;
}

bool CheckLeftedge(const Ball & ball1, int step_ball) {
	int width = LabGetWidth();
	int height = LabGetHeight();
	for (int circle_angle = 0; circle_angle <= 360; circle_angle += 3) {
		if (ball1.x + ball1.r * cos(radian() * circle_angle) <= 0) {
			return true;
		}
	}
	return false;
}
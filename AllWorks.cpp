#include "AllWorks.h"


void AllWorks(void) {
	int width = LabGetWidth();
	int height = LabGetHeight();
	int width_block = width / 10;
	int height_block = height / 30;
	vector<vector <Block*>> blocks;
	labkey_t button;
	time_t start, end;
	Hit blow;
	int delay = 15;
	int personal_account = 0;

	LabSetColor(LABCOLOR_WHITE);
	int row_size = 5;
	int column_size = 6;
	blocks.resize(row_size);
	for (int i = 0; i < row_size; i++) {
		blocks[i].resize(column_size);
	}

	//делаю физику движений
	int width_catch = width / 4;
	int height_catch = height / 33;
	Catch catcher(width / 2 - (width_catch / 2), height - height_catch, width / 2 + (width_catch / 2), height);
	catcher.life_count = 1;

	int ball_center_x = width / 2;
	int rad_ball = 8;
	int first_angle = 100;
	int step_ball = 7;
	int ball_center_y = height - height_catch - rad_ball;
	Ball ball1(ball_center_x, ball_center_y, rad_ball, first_angle, delay, step_ball);

	int step_bonus = 5;
	int step_catcher = 30;
	//построить блоки

	Buildingblocks(blocks, row_size, column_size, &catcher, &ball1);
	

	time(&start);
	while (1) {
		DrawBlocks(blocks, row_size, column_size);
		DrawBOnuses(blocks, row_size, column_size);
		catcher.Draw();
		ball1.Draw();
		LabDrawFlush();
		LabDelay(ball1.delay);
		LabClear();
		if (ball1.start_move_flag && !LabInputKeyReady()) {

			//проверка на попадание в блок
			blow = ChekBlockDestroy(ball1, blocks, &personal_account, row_size, column_size);
			if (blow != missed) {
				if (blow == horizontal_blow) {
					ball1.angle = (180 - ball1.angle);
					ball1.Move();
				}
				else if (blow == vertical_blow) {
					ball1.angle = (360 - ball1.angle);
					ball1.Move();
				}
			}

			//проверк на прилипание
			else if (Check_ball_stick(ball1, catcher)) {
				ball1.start_move_flag = 0;
				continue;
			}

			//проверка на попадания в ловца
			else if (CathcerDown(catcher, ball1)) {
				ball1.angle = (360 - ball1.angle);
				ball1.Move();
			}

			//проверка на выход вверх
			else if (CheckUp(ball1, step_ball)) {
				ball1.angle = (360 - ball1.angle);
				ball1.Move();
			}

			//попадание шарика на правую стенку
			else if (CheckRightedge(ball1, step_ball)) {
				ball1.angle = (180 - ball1.angle);
				ball1.Move();
				if (CheckNewedge(ball1, step_ball)) ball1.Move();
			}

			//попадание на левую стенку
			else if (CheckLeftedge(ball1, step_ball)) {
				ball1.angle = (180 - ball1.angle);
				ball1.Move();
				if (CheckNewedge(ball1, step_ball)) ball1.Move();
			}

			//проверка на то что мяч упал
			else if (CheckDeparture(catcher, ball1)) {
				if (ball1.trampoline_flag) { //если был трамплин(бонус)
					ball1.trampoline_flag = 0;
					ball1.angle = (360 - ball1.angle);
					cout << "Springboard triggered!!" << endl;
					ball1.Move();
				}
				else {
					catcher.Dec_life(); //атниамем жизнь ибо упал
					if (catcher.life_count == 0) {
						cout << "\n\nFailure!" << endl;
						cout << "Your points: " << personal_account << endl;
						time(&end);
						double seconds = difftime(end, start);
						cout << "Your time : " << seconds << " seconds." << endl;
						DrawBlocks(blocks, row_size, column_size);
						catcher.Draw();
						ball1.Draw();
						break;
					}
					else {
						Ball buf(catcher.x1 + (catcher.x2 - catcher.x1) / 2, catcher.y1 - rad_ball, rad_ball, first_angle,delay,step_ball);
						ball1 = buf;
						cout << "You have lost one life, you dull them with you:" << catcher.life_count << endl;
						continue;
					}
				}
			}

			//проверка на прохождение
			else if (CheckEndgame(blocks, row_size, column_size)) {
				cout << "\n\nNot bad!" << endl;
				cout << "Your points: " << personal_account << endl;
				time(&end);
				double seconds = difftime(end, start);
				cout << "Your time : " << seconds << " seconds." << endl;
				break;
			}

			//обработка упавших бонусов
			BlockDown(blocks,row_size, column_size, catcher);

			//проверка на то что мяч увеличился
			Check_ball_grow(ball1);

			//движение блоков
			BlockRun(blocks, row_size, column_size);
			ball1.Move();
			MoveBonuses(blocks, step_bonus, row_size, column_size);
			continue;
		}

		button = LabInputKey();
		switch (button) {
		case LABKEY_ENTER:
			if (ball1.start_move_flag == 0) {
				if (ball1.stick_count == 0) ball1.Move();
				else {
					ball1.angle = (360 - ball1.angle);
					ball1.Move();
				}
				ball1.start_move_flag = 1;
				if (ball1.stick_count != 0) {
					ball1.Dec_stick(); //прилипиние
					cout << "The ball will stick " << ball1.stick_count << " more times!" << endl;
				}
			}
			break;
		case LABKEY_LEFT:
			if (catcher.x1 - step_catcher >= 0) {
				catcher.Move(-step_catcher);
				if (!ball1.start_move_flag) {
					ball1.x = ball1.x - step_catcher;
				}
			}
			else if (catcher.x1 <= (step_catcher) && catcher.x1 > 0) {
				int buff = catcher.x1;
				catcher.Move(-catcher.x1);
				if (!ball1.start_move_flag) {
					ball1.x = ball1.x - buff;
				}
			}
			break;
		case LABKEY_RIGHT:
			if (catcher.x2 + step_catcher <= (width)) {
				catcher.Move(step_catcher);
				if (!ball1.start_move_flag) {
					ball1.x = ball1.x + step_catcher;
				}
			}
			else if (width - catcher.x2 <= (step_catcher) && catcher.x2 < width) {
				int buff = width - catcher.x2;
				catcher.Move(width - catcher.x2);
				if (!ball1.start_move_flag) {
					ball1.x = ball1.x + buff;
				}
			}
			break;

		case LABKEY_ESC:
			return;
		}
	}
}
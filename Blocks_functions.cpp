
#include "Blocks_functions.h"
#include "Catch.h"
#include "Ball.h"

void Buildingblocks(vector<vector <Block*>> & blocks, int row_size, int column_size,Catch * catcher, Ball * ball1) {
	int width = LabGetWidth();
	int height = LabGetHeight();

	int width_block = width / 7;
	int height_block = height / 20;

	blocks[0][0] = new Block_dinamic(50, 50, width_block + 50, height_block + 50);

	for (int i = 1; i < row_size; i++) { //формирую 1 столбец
		if (i != row_size - 1) blocks[i][0] = new Block_three(50, blocks[i - 1][0]->y2, width_block + 50, blocks[i - 1][0]->y2 + height_block);
		else blocks[i][0] = new Block_dinamic(50, blocks[i - 1][0]->y2, width_block + 50, blocks[i - 1][0]->y2 + height_block);
	}

	for (int j = 0; j < row_size; j++) {
		for (int i = 1; i < column_size; i++) {
			if ((j == 0 || j == row_size - 1) && i != column_size - 1) {//“–ќ… » закидываю кроме боковых
				blocks[j][i] = new Block_three(blocks[j][i - 1]->x2, blocks[j][i - 1]->y1, blocks[j][i - 1]->x2 + width_block, blocks[j][i - 1]->y2);
			}
			else if ((j == 1 && i != column_size - 1) || ((i == 1 || i == column_size - 2) && j != 0 && j != row_size - 1)) { //все единицы
				blocks[j][i] = new Block_one(blocks[j][i - 1]->x2, blocks[j][i - 1]->y1, blocks[j][i - 1]->x2 + width_block, blocks[j][i - 1]->y2);
			}
			else if ((j == 2 || j == 3) && (i == 2 || i == 3)) { //золотые
				blocks[j][i] = new Block_strong(blocks[j][i - 1]->x2, blocks[j][i - 1]->y1, blocks[j][i - 1]->x2 + width_block, blocks[j][i - 1]->y2); // нерушимые
			}
			else if ((i == column_size - 1) && j != 0 && j != row_size - 1) { //крайние тройки
				blocks[j][i] = new Block_three(blocks[j][i - 1]->x2, blocks[j][i - 1]->y1, blocks[j][i - 1]->x2 + width_block, blocks[j][i - 1]->y2);
			}
			else if (i == column_size - 1 && (j == 0 || j == row_size - 1)) { //крайние двигающиес€
				blocks[j][i] = new Block_dinamic(blocks[j][i - 1]->x2, blocks[j][i - 1]->y1, blocks[j][i - 1]->x2 + width_block, blocks[j][i - 1]->y2); // нерушимые
			}
			else blocks[j][i] = new Block_three(blocks[j][i - 1]->x2, blocks[j][i - 1]->y1, blocks[j][i - 1]->x2 + width_block, blocks[j][i - 1]->y2); // в слча если увличили число блоков
		}
	}
	for (int j = 0; j < row_size; j++) {
		for (int i = 0; i < column_size; i++) {
			int step_cather = 20;
			int delta_rad = 6;
			int sticks = 3;
			if (j == row_size - 1) { //добавл€ю бонусы
				switch (i) {
				case 0:
					blocks[j][i]->bonus_block = new Bonus_ball_stick(ball1, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3, sticks);
					break;

				case 1:
					blocks[j][i]->bonus_block = new Bonus_catcher_less(catcher, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3, step_cather);
					break;
				
				case 2:
					blocks[j][i]->bonus_block = new Bonus_plus_life (catcher, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3);
					break;
				case 3:
					blocks[j][i]->bonus_block = new Bonus_speed_ball (ball1, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3);
					break;
				case 4:
					blocks[j][i]->bonus_block = new Bonus_slow_ball(ball1, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3);
					break;
				case 5:
					blocks[j][i]->bonus_block = new Bonus_ball_increase(ball1, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3,delta_rad);
					break;
				}
				blocks[j][i]->ChangeBonus(1);
			}
			else if (j == row_size - 2) {
				switch (i) {
				case 0:
					blocks[j][i]->bonus_block = new Bonus_catcher_more(catcher, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3, step_cather);
					break;
				case 1:
					blocks[j][i]->bonus_block = new Bonus_ball_stick(ball1, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3, sticks);
					break;
				case 2:
					blocks[j][i]->bonus_block = new Bonus_trampline(ball1, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3);
					break;
				case 3:
					blocks[j][i]->bonus_block = new Bonus_catcher_more(catcher, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 33, step_cather);
					break;
				case 4:
					blocks[j][i]->bonus_block = new Bonus_trampline(ball1, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3);
					break;
				case 5:
					blocks[j][i]->bonus_block = new Bonus_trampline(ball1, blocks[j][i]->x1 + 25, blocks[j][i]->y1 + 3, blocks[j][i]->x2 - 25, blocks[j][i]->y2 - 3);
					break;
				}
				blocks[j][i]->ChangeBonus(1);
			}
			else blocks[j][i]->ChangeBonus(0);
			blocks[j][i]->flag_destroy = 0;
		}
	}
}

bool CheckCatchBonus(int x_buf1, int x_buf2, int y_buf1, const Catch & catcher) {
	if (((x_buf1 < catcher.x2 && x_buf2 > catcher.x2) || (x_buf2 > catcher.x1 && x_buf1 < catcher.x1) || (x_buf2 <= catcher.x2 && x_buf1 >= catcher.x1)) && (y_buf1 >= catcher.y1 && y_buf1 <= catcher.y2))
		return true;
	else return false;
}

void RealeseDownBonus(Block * block, const Catch & catcher) {
	int height = LabGetHeight();
	if (block->CheckActiveBonuse()) {
			if(CheckCatchBonus(block->bonus_block->x1, block->bonus_block->x2, block->bonus_block->y2, catcher))  {
				block->bonus_block->Realise_bonus();
			}
			else if (block->bonus_block->y2 >= height) {
				block->bonus_block->move_bonus_flag = 0;
				block->bonus_block->destroy_flag = 1;
			}
	}
}

void BlockDown(vector<vector <Block*>> & blocks, int row_size, int column_size, const Catch & catcher) {
	for (int j = 0; j < row_size; j++) {
		for (int i = 0; i < column_size; i++) {
			RealeseDownBonus(blocks[j][i],catcher);
		}
	}
}

void DrawBlocks(vector<vector <Block*>> & blocks, int row_size, int column_size) {
	for (int j = 0; j < row_size; j++) {
		for (int i = 0; i < column_size; i++) {
			blocks[j][i]->Draw();
		}
	}
}


Hit ChekBlockDestroy(Ball & ball1, vector<vector <Block*>> & blocks, int * personal_account, int row_size, int column_size) {

	int circle_angle = 0;
	for (int j = 0; j < row_size; j++) {
		for (int i = 0; i < column_size; i++) {
			for (int circle_angle = (int)ball1.angle; circle_angle <= 360 + ball1.angle - 1; circle_angle += 3) {
				double x_buf = (ball1.x + (ball1.r + 1) * cos(radian() * circle_angle));
				double y_buf = (ball1.y - (ball1.r + 1) * sin(radian() * circle_angle));
				if (x_buf <= blocks[j][i]->x2 && x_buf >= blocks[j][i]->x1 && (!blocks[j][i]->flag_destroy)) {
					if (y_buf >= blocks[j][i]->y1 && y_buf <= blocks[j][i]->y2 && (!blocks[j][i]->flag_destroy)) {

						// удар по блоку -> отнимаем жизнь
						if (blocks[j][i]->GetSmash()) {
							blocks[j][i]->DecCountLife();
							if (blocks[j][i]->GetLifeCount() == 0) {
								blocks[j][i]->flag_destroy = 1;
								if (blocks[j][i]->GetMobile_flag()) (*personal_account) += 2;
								else (*personal_account) += 1;
								cout << "Your points: " << *personal_account << endl;
								if (blocks[j][i]->GetBonus()) {
									blocks[j][i]->bonus_block->move_bonus_flag = 1; //активирую движение бонуса
								}
							}
						}

						// определ€ю сторону удара
						if (ball1.x >= blocks[j][i]->x1 && ball1.x <= blocks[j][i]->x2) {
							return vertical_blow;
						}

						else if (ball1.x < blocks[j][i]->x1 || ball1.x > blocks[j][i]->x2) {
							if (ball1.y >= blocks[j][i]->y1 && ball1.y <= blocks[j][i]->y2) {
								return horizontal_blow;
							}
							else {
								return vertical_blow;
							}
						}
					}
				}
			}
		}
	}
	return missed;
}


void BlockRun(vector<vector <Block*>> & blocks, int  row_size, int column_size) {
	int width = LabGetWidth();
	int height = LabGetHeight();
	int step_block = blocks[0][0]->step_block;
	for (int j = 0; j < row_size; j++) {
		for (int i = 0; i < column_size; i++) {
			if (blocks[j][i]->GetMobile_flag()) {
				if (i == 0) {
					if (blocks[j][i]->GetSide() == straight) { //пр€мое движение(начальное)
						if ((blocks[j][i]->x1 > 0) && (blocks[j][i]->x1 > step_block)) {
							blocks[j][i]->BlockMove(-step_block);
						}
						else if ((blocks[j][i]->x1 <= step_block) && (blocks[j][i]->x1 >= 0)) {
							blocks[j][i]->BlockMove(-blocks[j][i]->x1);
							blocks[j][i]->ChangeSide(back); //терь можно поврнуть, ибо до кра€ дошли
						}
					}
					else if (blocks[j][i]->GetSide() == back) {
						if ((blocks[j][i]->x2 < blocks[j][i + 1]->x1) && ((blocks[j][i + 1]->x1 - blocks[j][i]->x2) > step_block)) {
							blocks[j][i]->BlockMove(step_block);
						}
						else if (blocks[j][i]->x2 < blocks[j][i + 1]->x1 && (blocks[j][i + 1]->x1 - blocks[j][i]->x2) <= step_block) {
							blocks[j][i]->BlockMove(-(blocks[j][i]->x2 - blocks[j][i + 1]->x1));
							blocks[j][i]->ChangeSide(straight);
						}
					}
				}
				if (i == column_size - 1) {
					if (blocks[j][i]->GetSide() == straight) {
						if (blocks[j][i]->x2 < width && (width - blocks[j][i]->x2) > step_block) {
							blocks[j][i]->BlockMove(step_block);
						}
						else if (blocks[j][i]->x2 <= width && (width - blocks[j][i]->x2) <= step_block) {
							blocks[j][i]->BlockMove(width - blocks[j][i]->x2);
							blocks[j][i]->ChangeSide(back);
						}
					}
					else if (blocks[j][i]->GetSide() == back) {
						if (blocks[j][i]->x1 > blocks[j][i - 1]->x2 && (blocks[j][i]->x1 - blocks[j][i - 1]->x2) > step_block) {
							blocks[j][i]->BlockMove(-step_block);
						}
						else if (blocks[j][i]->x1 > blocks[j][i - 1]->x2 && (blocks[j][i]->x1 - blocks[j][i - 1]->x2) <= step_block) {
							blocks[j][i]->BlockMove(-(blocks[j][i]->x1 - blocks[j][i - 1]->x2));
							blocks[j][i]->ChangeSide(straight);
						}
					}
				}
			}
		}
	}
}
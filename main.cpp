#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "labengine.h"
#include "Blocks_functions.h"
#include "Ball.h"
#include "Handling_of_movements.h"
#include "AllWorks.h"
using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");
	if(LabInit())    // Инициализация
	{
		AllWorks();
		LabDrawFlush();
		LabInputKey();
	}
	return 0;
}
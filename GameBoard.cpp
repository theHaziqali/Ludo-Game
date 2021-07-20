/*
 * GameBoard.cpp
 *
 *  Created on: june 07, 2021
 *      Author: Haziq Ali
 */

#include "GameBoard.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "util.h"
using namespace std;

GameBoard::GameBoard() 
{
	for (int j = 40, k = 0; j < 840; j = j + 50, k++)
		x_array.push_back(j);
	for (int j = 39, k = 0; j < 840; j = j + 50, k++)
		y_array.push_back(j);
		//ludo indexes
	//red box index
	for (int j = 465, k = 0; k<3; j = j - 50, k++)
		coordinate_x.push_back(j);
	for (int j = 315, k = 0; k<6; j = j - 50, k++)
		coordinate_y.push_back(j);
	// yellow box index	
	for (int j = 315, k = 0; k<6; j = j - 50, k++)
		coordinate_x.push_back(j);
	for (int j = 365, k = 0; k<3; j = j + 50, k++)
		coordinate_y.push_back(j);
	// blue indexes
	for (int j = 515, k = 0; k<6; j = j + 50, k++)
		coordinate_y.push_back(j);
	// green indexes
	for (int j = 515, k = 0; k<6; j = j + 50, k++)
		coordinate_x.push_back(j);
		//
		
		coordinate_x.push_back(120);
		coordinate_x.push_back(250);
		coordinate_x.push_back(580);
		coordinate_x.push_back(700);

		//
		coordinate_y.push_back(130);
		coordinate_y.push_back(250);
		coordinate_y.push_back(570);
		coordinate_y.push_back(710);
	x = y = 0; 
}
void *GameBoard::DrawBoard()
{
	for (int k = 0; k < 6; k++)
	{
		// cout<<x_array[6]<<endl<<x_array[7]<<endl<<x_array[8];
		DrawSquare(x_array[6], y_array[k], 50, colors[GRAY]);
		if(k>0)
			DrawSquare(x_array[7], y_array[k], 50, colors[RED]);

		else 
			DrawSquare(x_array[7], y_array[k], 50, colors[GRAY]);
			
		DrawSquare(x_array[8], y_array[k], 50, colors[GRAY]);
	}
		DrawSquare(x_array[8], y_array[2], 50, colors[RED]);
		DrawSquare(x_array[6], y_array[1], 50, colors[RED]);
	for (int k = 0; k < 6; k++)
	{
		DrawSquare((x_array[k]), y_array[6], 50, colors[GRAY]);
		if(k>0)
			DrawSquare((x_array[k]), y_array[7], 50, colors[DARK_GOLDEN_ROD]);
		else 
			DrawSquare((x_array[k]), y_array[7], 50, colors[GRAY]);
		DrawSquare((x_array[k]), y_array[8], 50, colors[GRAY]);
	}
		DrawSquare(x_array[2], y_array[6], 50, colors[DARK_GOLDEN_ROD]);
		DrawSquare(x_array[1], y_array[8], 50, colors[DARK_GOLDEN_ROD]);	
	for (int k = 9; k < 15; k++)
	{
		DrawSquare((x_array[k]), (y_array[6]), 50, colors[GRAY]);
		if(k<14)
			DrawSquare((x_array[k]), y_array[7], 50, colors[GREEN]);

		else 
			DrawSquare(x_array[k], y_array[7], 50, colors[GRAY]);
		DrawSquare((x_array[k]), y_array[8], 50, colors[GRAY]);
	}
		DrawSquare(x_array[13], y_array[6], 50, colors[GREEN]);
		DrawSquare(x_array[12], y_array[8], 50, colors[GREEN]);	
	for (int k = 14; k > 8; k--)
	{
		// cout<<x_array[6]<<endl<<x_array[7]<<endl<<x_array[8];
		DrawSquare(x_array[6], y_array[k], 50, colors[GRAY]);
		if(k<14)
			DrawSquare(x_array[7], y_array[k], 50, colors[BLUE]);
		else 
			DrawSquare(x_array[7], y_array[k], 50, colors[GRAY]);

		DrawSquare(x_array[8], y_array[k], 50, colors[GRAY]);
	}
		DrawSquare(x_array[6], y_array[12], 50, colors[BLUE]);
		DrawSquare(x_array[8], y_array[13], 50, colors[BLUE]);	

	//////////////////////////////////////////////////////////
	DrawSquare(x_array[6], y_array[6], 100, colors[AQUA]);
	DrawSquare(x_array[7], y_array[6], 100, colors[AQUA]);
	DrawSquare(x_array[6], y_array[7], 100, colors[AQUA]);
	DrawSquare(x_array[7], y_array[7], 100, colors[AQUA]);

	DrawSquare(x_array[0], y_array[9], 300, colors[DARK_GOLDEN_ROD]);
	DrawSquare(x_array[1], y_array[10], 200, colors[WHITE]);

	DrawSquare(x_array[0], y_array[0] , 300, colors[RED]);
	DrawSquare(x_array[1], y_array[1] , 200, colors[WHITE]);

	DrawSquare(x_array[9], y_array[0] , 300, colors[GREEN]);
	DrawSquare(x_array[10], y_array[1], 200, colors[WHITE]);

	DrawSquare(x_array[9], y_array[9], 300, colors[BLUE]);
	DrawSquare(x_array[10], y_array[10], 200, colors[WHITE]);
	//Token_moving();
}
void GameBoard::Token_moving()
{
	DrawCircle(coordinate_x[16], coordinate_y[15], 15, colors[MAROON]);
	DrawCircle(coordinate_x[15], coordinate_y[15], 15, colors[MAROON]);
	DrawCircle(coordinate_x[16], coordinate_y[16], 15, colors[MAROON]);
	DrawCircle(coordinate_x[15], coordinate_y[16], 15, colors[MAROON]);


	DrawCircle(coordinate_x[15], coordinate_y[17], 15, colors[GOLD]);
	DrawCircle(coordinate_x[16], coordinate_y[17], 15, colors[DARK_GOLDEN_ROD]);
	DrawCircle(coordinate_x[16], coordinate_y[18], 15, colors[DARK_GOLDEN_ROD]);
	DrawCircle(coordinate_x[15], coordinate_y[18], 15, colors[DARK_GOLDEN_ROD]);


	DrawCircle(coordinate_x[17], coordinate_y[17], 15, colors[AQUA]);
	DrawCircle(coordinate_x[18], coordinate_y[17], 15, colors[AQUA]);
	DrawCircle(coordinate_x[17], coordinate_y[18], 15, colors[AQUA]);
	DrawCircle(coordinate_x[18], coordinate_y[18], 15, colors[AQUA]);

	DrawCircle(coordinate_x[17], coordinate_y[16], 15, colors[FOREST_GREEN]);
	DrawCircle(coordinate_x[18], coordinate_y[15], 15, colors[GREEN]);
	DrawCircle(coordinate_x[17], coordinate_y[15], 15, colors[GREEN]);
	DrawCircle(coordinate_x[18], coordinate_y[16], 15, colors[GREEN]);


}
/*
void *GameBoard::RollDice(vector<Player> Players)
{
	InitRandomizer();
	roll.clear();
	for (int counter = 0; counter < players.size(); counter++)
	{
		roll.push_back(players[counter].Roll()); //Call random function to decide roll value
		
	}
	return NULL;
}
*/
void *GameBoard::DecideTurn()
{
	int random = 0;
	turns.clear(); //Clear the vector
	for (int counter = 0; turns.size() != 4; counter++)
	{
		random = rand() % 4 + 1;
		if (find(turns.begin(), turns.end(), random) == turns.end()) //If value not present, then insert
		{
			turns.push_back(random);
			cout << "turn " << turns.size() << ": " << random << endl;
		}
	}
}

void* GameBoard::Turn(void* arg) {
	
}

/*void *GameBoard::isMatch()
{
	for (int counter = 0; counter < 4; counter++)
	{
		for (int count = 0; count < 4; count++)
		{
			for (int count2 = 0; count2 < players[count].coordinate_x.size(); count2++) {
				if ((find(players[counter].coordinate_x.begin(), players[counter].coordinate_x.end(), players[count].coordinate_x[count2]) == players[counter].coordinate_x.end()) && (find(players[counter].coordinate_y.begin(), players[counter].coordinate_y.end(), players[count].coordinate_y[count2]) == players[counter].coordinate_y.end())) {
					//Goti match
					if(turns[counter] < turns[count]) {
						players[count].score++; //1 hit
					}
					else {
						players[counter].score++; //1 hit
					}
					return NULL;
				}
			}
		}
	}
}

*/

GameBoard::~GameBoard()
{
}

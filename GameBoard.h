/*
 * GameBoard.h
 *
 *  Created on: june 07, 2021
 *      Author: Haziq Ali
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_
#include <iostream>
#include <vector>
//#include"Player.h"
//#include "GameBoard.cpp"

using namespace std;
class GameBoard  {

public:
		vector<int> x_array;
		vector<int> y_array;
		vector<int> roll;
		int x,y;		
		vector<int> turns;
		vector<int> coordinate_x;	//ludo index x
		vector<int> coordinate_y;	//ludo index y
	//double x1, y1;
	GameBoard();//{
	void* DrawBoard();
	//void* RollDice( vector<Player>);
	void* DecideTurn();
	void* isMatch();
	static void* Turn(void*);
	void Token_moving();
	//}
/*	GameBoard(int, bool);
	GameBoard(const GameBoard &other);
	int gettime()const;
	void updatetime(int);
	bool getstate()const;
	void setstate(bool);
	bool isLost();
	bool isWon();

	void SwapGems(double,double,double,double);
	bool isMatch(double,double);
	void updatelevel();
	void DropGems();
	void GiveHint();
*/
	~GameBoard();
};

#endif /* GAMEBOARD_H_ */

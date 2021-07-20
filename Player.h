/*
 * Player.h
 *
 *  Created on: May 9, 2020
 *      Author: danyal-faheem
 */
#ifndef PLAYER_H_
#define PLAYER_H_
#include "Token.h"
#include "GameBoard.h"
#include <iostream>
#include <string>
#include <vector>
#include"util.h"
//#include<GameBoard.h>
using namespace std;
class Player :public GameBoard{
public:
	ColorNames color;
	int score, hit, tokens, roll; 
		vector<int> x_co, y_co;

	Token* geti=new Token[4];
	Player();
	Player(ColorNames n, int);
	Player(const Player &other);
	void DrawTokens();
	void Tokening();
	string getcolor() const;
	void setcolor(ColorNames);
	int getscore() const;
	void setscore(int);
	int gethit() const;
	void sethit(int);
	int getroll() const;
	void setroll(int);
	int Roll();
	int gettokens() const;
	void settokens(int);
	void set(int, int, int);

	//Player operator=(const Player&);
};

#endif /* PLAYER_H_ */

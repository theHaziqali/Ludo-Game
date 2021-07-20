/*
 * Token.cpp
 *
 *  Created on: May 9, 2020
 *      Author: danyal-faheem
 */

#include "Token.h"
#include "util.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

Token::Token()
{ // Default constructor to randomly assign colors to Tokens
	InitRandomizer();
	//x = y = 0;
	// color = " ";
	active = 0;
	index = -1;
}

Token::Token(string t)
{
	// color = t;
	//x = y = 0;
	active = 0;
	index = -1;
}

Token::Token(const Token &other)
{
	color = other.color;
	x = other.x;
	y = other.y;
}

void Token::setcolor(string t)
{
	//   color = t;
}

string Token::getcolor() const
{
	//  return color;
}

void Token::DrawToken()
{ // Main function which draws the Tokens on the board according to the random colors assigned in the default constructor
	DrawCircle(x, y, 15, colors[color]);
	//cout << color << ": " << x << " " << y << endl;
	// cout<<"yayyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy"<<endl;
}
void Token::RunToken(int roll, vector<int> co_x, vector<int> co_y, int hit)
{

	if ((roll >= 6) and (active == 0))
	{
	cout<<"helllo ggg"<<endl;
		active = 1;
		index = 0;
		x = co_x[index];
		y = co_y[index];
		DrawToken();
		index += roll - 6;
		x = co_x[index];
		y = co_y[index];
		DrawToken();
	}
	 if (active == 1)
	{
		index += roll; //normal
		cout<<"index:"<<index<<endl;
		if (index > 51 and hit < 1) // Do another round
		{
			index = index % 57;
		}
		else if (index < 57) //Move token around
		{	
			x = co_x[index];
			y = co_y[index];
			DrawToken();
		}
		else if (index == 57 and hit > 0) { //Goti pug gayi
			x = 420;
			y = 420;
			active = 2;
			DrawToken();
		}

	}
	if (active == 0) {
		DrawToken();
	}
}

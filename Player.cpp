/*
* Player.cpp
*
*  Created on: May 9, 2020
*      Author: danyal-faheem
*/

#include "Player.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include "util.h"

using namespace std;

Player::Player()
{
	// TODO Auto-generated constructor stub
	//color = " ";
	//	hit = score = 0;

	//	y_array.push_back(j);
}

Player::Player(ColorNames n, int tok)
{

	color = n;
	tokens = tok;
	//cout << "tokens: " << tok << endl;
	if ((n == MAROON))
	{
		//cout << "Red: ";

		for (int k = 0; k < 4; k++)
			geti[k].color = MAROON;

		geti[0].x = coordinate_x[16];
		geti[0].y = coordinate_y[15];
		geti[1].x = coordinate_x[15];
		geti[1].y = coordinate_y[15];
		geti[2].x = coordinate_x[16];
		geti[2].y = coordinate_y[16];
		geti[3].x = coordinate_x[15];
		geti[3].y = coordinate_y[16];
		//cout << coordinate_x[16] << " :: " << coordinate_x[15] << endl; 
		for (int counter = 4; counter >= 0; counter--)
		{
			x_co.push_back(coordinate_x[2]);
			y_co.push_back(coordinate_y[counter]);
		}
		for (int counter = 3; counter <= 8; counter++)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[6]);
		}
		x_co.push_back(coordinate_x[8]);
		y_co.push_back(coordinate_y[7]);
		x_co.push_back(coordinate_x[8]);
		y_co.push_back(coordinate_y[8]);
		for (int counter = 7; counter >= 3; counter--)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[8]);
		}
		for (int counter = 9; counter <= 14; counter++)
		{
			x_co.push_back(coordinate_x[2]);
			y_co.push_back(coordinate_y[counter]);
		}
		x_co.push_back(coordinate_x[1]);
		y_co.push_back(coordinate_y[14]);
		x_co.push_back(coordinate_x[0]);
		y_co.push_back(coordinate_y[14]);
		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[0]);
			y_co.push_back(coordinate_y[counter]);
		}
		for (int counter = 9; counter <= 14; counter++)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[8]);
		}
		x_co.push_back(coordinate_x[14]);
		y_co.push_back(coordinate_y[7]);
		x_co.push_back(coordinate_x[14]);
		y_co.push_back(coordinate_y[6]);
		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[6]);
		}
		for (int counter = 0; counter <= 5; counter++)
		{
			x_co.push_back(coordinate_x[0]);
			y_co.push_back(coordinate_y[counter]);
		}
		x_co.push_back(coordinate_x[1]);
		y_co.push_back(coordinate_y[5]);
		for (int counter = 4; counter >= 0; counter--)
		{
			x_co.push_back(coordinate_x[1]);
			y_co.push_back(coordinate_y[counter]);
		}
		x_co.push_back(coordinate_x[2]);
		y_co.push_back(coordinate_y[5]);
	}
	else if ((n == GOLD))
	{
		//cout << "Gold: ";

		for (int k = 0; k < 4; k++)
			geti[k].color = n;

		geti[0].x = coordinate_x[15];
		geti[0].y = coordinate_y[17];
		geti[1].x = coordinate_x[16];
		geti[1].y = coordinate_y[17];
		geti[2].x = coordinate_x[16];
		geti[2].y = coordinate_y[18];
		geti[3].x = coordinate_x[15];
		geti[3].y = coordinate_y[18];
		for (int counter = 7; counter >= 3; counter--)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[8]);
		}
		for (int counter = 9; counter <= 14; counter++)
		{
			x_co.push_back(coordinate_x[2]);
			y_co.push_back(coordinate_y[counter]);
		}
		x_co.push_back(coordinate_x[1]);
		y_co.push_back(coordinate_y[14]);
		x_co.push_back(coordinate_x[0]);
		y_co.push_back(coordinate_y[14]);
		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[0]);
			y_co.push_back(coordinate_y[counter]);
		}
		for (int counter = 9; counter <= 14; counter++)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[8]);
		}
		x_co.push_back(coordinate_x[14]);
		y_co.push_back(coordinate_y[7]);
		x_co.push_back(coordinate_x[14]);
		y_co.push_back(coordinate_y[6]);
		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[6]);
		}
		for (int counter = 0; counter <= 5; counter++)
		{
			x_co.push_back(coordinate_x[0]);
			y_co.push_back(coordinate_y[counter]);
		}
		x_co.push_back(coordinate_x[1]);
		y_co.push_back(coordinate_y[5]);
		x_co.push_back(coordinate_x[2]);
		y_co.push_back(coordinate_y[5]);
		for (int counter = 4; counter >= 0; counter--)
		{
			x_co.push_back(coordinate_x[2]);
			y_co.push_back(coordinate_y[counter]);
		}
		for (int counter = 3; counter <= 8; counter++)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[6]);
		}
		x_co.push_back(coordinate_x[8]);
		y_co.push_back(coordinate_y[7]);
		for (int counter = 7; counter >= 3; counter--)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[7]);
		}
		x_co.push_back(coordinate_x[8]);
		y_co.push_back(coordinate_y[8]);
	}
	else if ((n == AQUA))
	{
		//cout << "Aqua: ";
		
		for (int k = 0; k < 4; k++)
			geti[k].color = n;

		geti[0].x = coordinate_x[17];
		geti[0].y = coordinate_y[17];
		geti[1].x = coordinate_x[18];
		geti[1].y = coordinate_y[17];
		geti[2].x = coordinate_x[17];
		geti[2].y = coordinate_x[18];
		geti[3].x = coordinate_y[18];
		geti[3].y = coordinate_y[18];
		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[0]);
			y_co.push_back(coordinate_y[counter]);
		}
		for (int counter = 9; counter <= 14; counter++)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[8]);
		}
		x_co.push_back(coordinate_x[14]);
		y_co.push_back(coordinate_y[7]);
		x_co.push_back(coordinate_x[14]);
		y_co.push_back(coordinate_y[6]);
		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[6]);
		}
		for (int counter = 0; counter <= 5; counter++)
		{
			x_co.push_back(coordinate_x[0]);
			y_co.push_back(coordinate_y[counter]);
		}
		x_co.push_back(coordinate_x[1]);
		y_co.push_back(coordinate_y[5]);
		x_co.push_back(coordinate_x[2]);
		y_co.push_back(coordinate_y[5]);
		for (int counter = 4; counter >= 0; counter--)
		{
			x_co.push_back(coordinate_x[2]);
			y_co.push_back(coordinate_y[counter]);
		}
		for (int counter = 3; counter <= 8; counter++)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[6]);
		}
		x_co.push_back(coordinate_x[8]);
		y_co.push_back(coordinate_y[7]);
		x_co.push_back(coordinate_x[8]);
		y_co.push_back(coordinate_y[8]);
		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[8]);
		}
		for (int counter = 9; counter <= 14; counter++)
		{
			x_co.push_back(coordinate_x[2]);
			y_co.push_back(coordinate_y[counter]);
		}
		x_co.push_back(coordinate_x[1]);
		y_co.push_back(coordinate_y[14]);
		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[1]);
			y_co.push_back(coordinate_y[counter]);
		}
		x_co.push_back(coordinate_x[0]);
		y_co.push_back(coordinate_y[14]);
	}

	else if ((n == FOREST_GREEN))
	{
		for (int k = 0; k < 4; k++)
			geti[k].color = n;

		geti[0].x = coordinate_x[17];
		geti[0].y = coordinate_y[16];
		geti[1].x = coordinate_x[18];
		geti[1].y = coordinate_y[15];
		geti[2].x = coordinate_x[17];
		geti[2].y = coordinate_x[15];
		geti[3].x = coordinate_y[18];
		geti[3].y = coordinate_y[16];

		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[6]);
		}
		for (int counter = 0; counter <= 5; counter++)
		{
			x_co.push_back(coordinate_x[0]);
			y_co.push_back(coordinate_y[counter]);
		}
		x_co.push_back(coordinate_x[1]);
		y_co.push_back(coordinate_y[5]);
		x_co.push_back(coordinate_x[2]);
		y_co.push_back(coordinate_y[5]);
		for (int counter = 4; counter >= 0; counter--)
		{
			x_co.push_back(coordinate_x[2]);
			y_co.push_back(coordinate_y[counter]);
		}
		for (int counter = 3; counter <= 8; counter++)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[6]);
		}
		x_co.push_back(coordinate_x[8]);
		y_co.push_back(coordinate_y[7]);
		x_co.push_back(coordinate_x[8]);
		y_co.push_back(coordinate_y[8]);
		for (int counter = 7; counter >= 3; counter--)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[8]);
		}
		for (int counter = 9; counter <= 14; counter++)
		{
			x_co.push_back(coordinate_x[2]);
			y_co.push_back(coordinate_y[counter]);
		}
		x_co.push_back(coordinate_x[1]);
		y_co.push_back(coordinate_y[14]);
		x_co.push_back(coordinate_x[0]);
		y_co.push_back(coordinate_y[14]);
		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[0]);
			y_co.push_back(coordinate_y[counter]);
		}
		for (int counter = 9; counter <= 14; counter++)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[8]);
		}
		x_co.push_back(coordinate_x[14]);
		y_co.push_back(coordinate_y[7]);
		for (int counter = 13; counter >= 9; counter--)
		{
			x_co.push_back(coordinate_x[counter]);
			y_co.push_back(coordinate_y[7]);
		}
		x_co.push_back(coordinate_x[14]);
		y_co.push_back(coordinate_y[6]);
		//
		
		//cout << "Green: ";
	}
	//cout << n << ": " << x_co.size() << "  " << y_co.size() << endl; 
		for (int k = 0; k < 4; k++) {
		this->geti[k].DrawToken();
		//cout << geti[k].x << "::" << geti[k].y << endl;
	}
}
void Player::Tokening()
{
	//sem_wait(&lock_player);
	int counter = 0;
	//InitRandomizer();
	roll = Roll();
	cout<<"-------------------------------------------------"<<endl;
	cout<<"roll:"<<roll<<" , ";
	if(color==0)
	cout<<"color: RED"<<endl;
	if(color==16)
	cout<<"color: YELLOW"<<endl;
	if(color==62)
	cout<<"color: GREEN"<<endl;
	if(color==47)
	cout<<"color: BLUE"<<endl;
	//cout<<"color: RED"<<<<endl;
	if(roll>6)
	{
		cout<<"-------------------------------------------------"<<endl;
		cout<<"Enter goti yo want to move"<<endl;
		cin>>counter;

	}
	//cout << color << ": " << roll << endl;
	//cout << "Hello world";
	//cout << "tokens tokening: " << tokens << endl;
//	for(int counter = 0; counter < tokens; counter++) 
		this->geti[counter].RunToken(roll, x_co, y_co, hit);

}

Player::Player(const Player &other)
{
	color = other.color;
	score = other.score;
}

string Player::getcolor() const
{
	//return color;
}

void Player::setcolor(ColorNames n)
{
	color = n;
}

int Player::gethit() const
{
	return hit;
}

void Player::sethit(int m)
{
	hit = m;
}

int Player::getroll() const
{
	return roll;
}

void Player::setroll(int m)
{
	roll = m;
}

int Player::Roll()
{
	InitRandomizer();
	   srand(time(0));

	roll = rand() % 6 + 1;
	if (roll == 6)
	{
		roll += rand() % 6 + 1; //Give bonus turn
		if (roll == 12)
		{
			roll += rand() % 6 + 1; //Second bonus turn
			if (roll == 18)			//Bari sar gayi
			{
				roll = 0;
			}
		}
	}
	return roll;
}
void Player::DrawTokens()
{
	//cout << "tokens: " << tokens << endl;
	for (int k = 0; k < tokens; k++) {
		this->geti[k].DrawToken();
		//cout << geti[k].x << "::" << geti[k].y << endl;
	}
}
void Player::setscore(int s)
{
	score = s;
}

int Player::gettokens() const
{
	return tokens;
}

void Player::settokens(int t)
{
	tokens = t;
}

int Player::getscore() const
{
	return score;
}

void Player::set(int s, int m, int l)
{
	score = s;
	hit = m;
}

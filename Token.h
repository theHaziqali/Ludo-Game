/*
 * Token.h
 *
 *  Created on: May 9, 2020
 *      Author: danyal-faheem
 */

#ifndef Token_H_
#define Token_H_
#include <iostream>
#include <string>
#include <vector>
#include"util.h"
//#include"Player.h"
using namespace std;

class Token  {
private:

public:
	int active;
	ColorNames color;
	//int id;
	int index;
	double x, y;
	Token();
	Token(string);
	Token(const Token &other);
	string getcolor() const;
	void setcolor(string);
	void DrawToken();
	void RunToken(int,vector<int>,vector<int>, int);

};

#endif /* Token_H_ */

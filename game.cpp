//============================================================================
// Name        : .cpp
// Author      : Danyal Faheem
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "GameBoard.h"
#include "Player.h"
#include<algorithm>
#include "util.h"
#include <iostream>
#include <vector>
#include<semaphore.h>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include <pthread.h>
using namespace std;
vector<int> turns;
sem_t lock_player; 
pthread_t tid[5];
GameBoard G;
int count = 0;
int tok = 0;
Player* players;
void Tokening(Player *plyr);
void No_tokens() {
	cout << "Enter number of tokens: ";
	cin >> tok;
	players = new Player[4]{Player(MAROON, tok),Player(GOLD, tok),Player(AQUA, tok),Player(FOREST_GREEN, tok)};
}
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
vector<int> rolls;

//pthread_t tid[5];
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
void* isMatch() {
	for (int counter = 0; counter < 4; counter++)
	{
		for (int count1 = 0; count1 < 4; count1++)
		{
			for (int count2 = 0; count2 < 57; count2++) {
				if ((find(players[counter].x_co.begin(), players[counter].x_co.end(), players[count1].x_co[count2]) != players[counter].x_co.end()) && (find(players[counter].y_co.begin(), players[counter].y_co.end(), players[count1].y_co[count2]) != players[counter].y_co.end()) && counter != count1) {
					//Goti match
					int count3 = 0;
					for (; count3 < 4; count3++) {
						if (turns[count3] == counter) {
							break;
						}
					}
					if(count3 < count1) {
						players[count1].hit++; //1 hit
					}
					else {
						players[counter].hit++; //1 hit
					}
					return NULL;
				}
			}
		}
	}
}
void *DecideTurn(void *arg)
{
	int random = 0;
	turns.clear(); //Clear the vector
	for (; turns.size() != 4;)
	{
		random = rand() % 4 + 1;
		if (find(turns.begin(), turns.end(), random) == turns.end()) //If value not present, then insert
		{
			turns.push_back(random);
			cout << "turn " << turns.size() << ": " << random << endl;
		}
	}
	isMatch();
}
void *RollDice()
{
	InitRandomizer();
	rolls.clear();
	for (int counter = 0; counter < 4; counter++)
	{
		rolls.push_back(players[counter].Roll()); //Call random function to decide roll value
		
	}
	return NULL;
}

void * DrawBoard(void* arg)
{
		for (int j = 40, k = 0; j < 840; j = j + 50, k++)
		G.x_array.push_back(j);
	for (int j = 40, k = 0; j < 840; j = j + 51, k++)
		G.y_array.push_back(j);
	for (int k = 0; k < 6; k++)
	{
		// cout<<G.x_array[6]<<endl<<G.x_array[7]<<endl<<G.x_array[8];
		DrawSquare(G.x_array[6], G.y_array[k], 50, colors[GRAY]);
		DrawSquare(G.x_array[7], G.y_array[k], 50, colors[RED]);
		DrawSquare(G.x_array[8], G.y_array[k], 50, colors[GRAY]);
	}

	for (int k = 0; k < 6; k++)
	{
		DrawSquare((G.x_array[k]), G.y_array[6], 50, colors[GRAY]);
		DrawSquare((G.x_array[k]), G.y_array[7], 50, colors[DARK_GOLDEN_ROD]);
		DrawSquare((G.x_array[k]), G.y_array[8], 50, colors[GRAY]);
	}

	for (int k = 9; k < 15; k++)
	{
		DrawSquare((G.x_array[k]), (G.y_array[6]), 50, colors[GRAY]);
		DrawSquare((G.x_array[k]), G.y_array[7], 50, colors[GREEN]);
		DrawSquare((G.x_array[k]), G.y_array[8], 50, colors[GRAY]);
	}
	for (int k = 14; k > 8; k--)
	{
		// cout<<G.x_array[6]<<endl<<G.x_array[7]<<endl<<G.x_array[8];
		DrawSquare(G.x_array[6], G.y_array[k], 50, colors[GRAY]);
		DrawSquare(G.x_array[7], G.y_array[k], 50, colors[BLUE]);
		DrawSquare(G.x_array[8], G.y_array[k], 50, colors[GRAY]);
	}
	//////////////////////////////////////////////////////////
	DrawSquare(G.x_array[6], G.y_array[6], 100, colors[AQUA]);
	DrawSquare(G.x_array[7], G.y_array[6], 100, colors[AQUA]);
	DrawSquare(G.x_array[6], G.y_array[7], 100, colors[AQUA]);
	DrawSquare(G.x_array[7], G.y_array[7], 100, colors[AQUA]);

	DrawSquare(G.x_array[0], G.y_array[9], 300, colors[DARK_GOLDEN_ROD]);
	DrawSquare(G.x_array[1], G.y_array[10], 200, colors[WHITE]);

	DrawSquare(G.x_array[0], G.y_array[0] + 5, 300, colors[RED]);
	DrawSquare(G.x_array[1], G.y_array[1] + 5, 200, colors[WHITE]);

	DrawSquare(G.x_array[9], G.y_array[0] + 5, 300, colors[GREEN]);
	DrawSquare(G.x_array[10], G.y_array[1] + 5, 200, colors[WHITE]);

	DrawSquare(G.x_array[9], G.y_array[9], 300, colors[BLUE]);
	DrawSquare(G.x_array[10], G.y_array[10], 200, colors[WHITE]);

	//DrawCircle(G.x_array[6] + 25, G.y_array[10] - 25, 15, colors[RED]);
	
		glutPostRedisplay();
}
/*
void* isMatch() {
	for (int counter = 0; counter < 4; counter++)
	{
		for (int count1 = 0; count1 < 4; count1++)
		{
			for (int count2 = 0; count2 < 57; count2++) {
				if ((find(players[counter].x_co.begin(), players[counter].x_co.end(), players[count1].x_co[count2]) != players[counter].x_co.end()) && (find(players[counter].y_co.begin(), players[counter].y_co.end(), players[count].y_co[count2]) != players[counter].y_co.end())) {
					//Goti match
					if(turns[counter] < turns[count1]) {
						players[count].hit++; //1 hit
					}
					else {
						players[counter].hit++; //1 hit
					}
					return NULL;
				}
			}
		}
	}
}
*/
void* func(void* arg) {
int *k=(int*)arg;

	//if(count < 57)
	 {
		Tokening(&players[*k]);
		//players[1].Tokening();
		//players[2].Tokening();
		//players[3].Tokening();
	}
	//count++;
	pthread_exit(NULL);
}
void Tokening(Player *plyr)
{
	//sem_wait(&lock_player);
	sem_wait(&lock_player);
	int counter = 0;
	
	InitRandomizer();
	plyr->roll = plyr->Roll();
	cout<<"-------------------------------------------------"<<endl;
	cout<<"roll:"<<plyr->roll<<" , ";
	if(plyr->color==0)
	cout<<"color: RED"<<endl;
	if(plyr->color==16)
	cout<<"color: YELLOW"<<endl;
	if(plyr->color==62)
	cout<<"color: GREEN"<<endl;
	if(plyr->color==47)
	cout<<"color: BLUE"<<endl;
	//cout<<"color: RED"<<<<endl;
	if(plyr->roll>6) 
	{
		cout<<"-------------------------------------------------"<<endl;
		cout<<"Enter goti yo want to move"<<endl;
		cin>>counter;
		plyr->geti[counter-1].RunToken(plyr->roll,plyr-> x_co, plyr->y_co,plyr-> hit);

	}
	
	for(int k=0;k<4;k++)
	{
		if (plyr->geti[k].active==1)
		plyr->geti[k].RunToken(plyr->roll,plyr-> x_co, plyr->y_co,plyr-> hit);
	
	}
	//cout << color << ": " << roll << endl;
	//cout << "Hello world";
	//cout << "tokens tokening: " << tokens << endl;
//	for(int counter = 0; counter < tokens; counter++) 
		plyr->geti[counter].RunToken(plyr->roll,plyr-> x_co, plyr->y_co,plyr-> hit);
			sem_post(&lock_player);
		//DO not write below this line
		glutPostRedisplay();
			

}




void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

		glClearColor(24/*Red Component*/, 20,	//148.0/255/*Green Component*/,
			12.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//DrawCircle(25, 25, 15, colors[RED]);
	//G.DrawBoard();
	
	G.DrawBoard();
	//players[0].setcolor(RED);
	for(int k=0;k<4;k++)
		players[k].DrawTokens();


//	players[0].geti[0].RunToken(6,G.coordinate_x[2],G.coordinate_y[4]);
	//players[1].geti[0].RunToken(6,G.coordinate_x[7],G.coordinate_y[8]);
	//players[2].geti[0].RunToken(6,G.coordinate_x[2],G.coordinate_y[4]);
	//players[3].geti[0].RunToken(6,G.coordinate_x[7],G.coordinate_y[8]);


/*	
	players[0].geti[0].DrawToken();
	players[1].geti[0].DrawToken();
	players[2].geti[0].DrawToken();
	players[3].geti[0].DrawToken();
*/	
	glutPostRedisplay();
	//cout << "Hello World1" << endl;
	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	//glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;
	}
	if (key == 32) { //Space bar pressed

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	
	DecideTurn(NULL);

	for(int k=0;k<4;k++){
	pthread_create(&tid[k], NULL, func, &k);
	pthread_join(tid[k], NULL);
	}
	
	//G.isMatch();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	//glutPostRedisplay();
}
/*
 * our gateway main function
 * */
struct arguments{
	int arg1;
	char** arg2;
	arguments() {
		arg1 = 0;
		arg2 = NULL;
	}
} args;
void * mainthread(void* arg) {
	No_tokens();
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...
	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	//InitRandomizer(); // seed the random number generator...
	glutInit(&(args.arg1), args.arg2); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("LUDO"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
			//pthread_create(&tid[0],NULL,glutDisplayFunc(GameDisplay),NULL);

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...

	//pthread_create(&tid[1], NULL, G.Turn, NULL);
	glutMainLoop();
	pthread_exit(NULL);
}


int main(int argc, char*argv[]) {
	sem_init(&lock_player,0,1); //semaphore intilization
	//sem_init(&lockie1,0,0);
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...
	args.arg1 = argc;
	args.arg2 = argv;
	InitRandomizer(); // seed the random number generator...

	pthread_create(&tid[0], NULL, mainthread, NULL);
	pthread_join(tid[0], NULL);
	
	//cout << "Hello World main\n";
	pthread_exit(NULL);
	/*int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
		glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("LUDO"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
			//pthread_create(&tid[0],NULL,glutDisplayFunc(GameDisplay),NULL);

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();*/
	return 1;
}
#endif 

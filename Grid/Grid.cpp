#include "Grid.hpp"
#include <sys/ioctl.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/*Constructor*/
Grid::Grid(){
	/*Needed to take terminal's dimensions*/
	struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    /*Allocate memory for grid*/
    map = new char*[w.ws_row];
    for (int i = 0; i < w.ws_row; ++i)
    	map[i] = new char[w.ws_col];

    /*Initialization grid*/

    /*Making borders*/
	for (int j = 0; j < w.ws_col; ++j){
		map[0][j] = '*';
		map[w.ws_row-1][j] = '*';
	}
	for (int i = 1; i < w.ws_row; ++i){
		map[i][0] = '*';
		map[i][w.ws_col-1] = '*';
	}

	/*Generate random map*/

	/*Generate non accessible fields*/
	for (int i = 1; i < w.ws_row-1; ++i)
		for (int j = 1; j < w.ws_col-1; ++j){
			if (rand()%100 < 5){
				map[i][j] = 'x';
			} else {map[i][j] = ' ';}
		}

	/*Hero's start position*/
	for (int j = 1; j < w.ws_col-1; ++j){
		if (map[1][j] == ' '){
			map[1][j] = 'h';
			xLoc = 1;
			yLoc = j;
			break;
		}
	}

	/*Market*/
	for (int j = w.ws_col-1; j >= 1; --j){
		if (map[1][j] == ' '){
			map[1][j] = 'M';
			break;
		}
	}

}

void Grid::mvUp(){
	int y2 = yLoc - 1;
	if (map[xLoc][y2] == ' '){
		map[xLoc][yLoc] == ' ';
		map[xLoc][y2] = 'h';
	}
}

void Grid::mvDown(){
	
	int x2 = xLoc + 1;
	if (map[x2][yLoc] == ' '){
		map[xLoc][yLoc] == ' ';
		map[x2][yLoc] = 'h';
	}
}

void Grid::mvRight(){
	int y2 = yLoc + 1;
	if (map[xLoc][y2] == ' '){
		map[xLoc][yLoc] == ' ';
		map[xLoc][y2] = 'h';
	}
}

void Grid::mvLeft(){
	int x2 = xLoc - 1;
	if (map[x2][yLoc] == ' '){
		map[xLoc][yLoc] == ' ';
		map[x2][yLoc] = 'h';
	}
}

char Grid::getmv(){
	char choice = getchar();
	switch(choice)
	{
		case 'w':
			mvUp();
			break;
		case 's':
			mvDown();
			break;
		case 'a':
			mvLeft();
			break;
		case 'd':
			mvRight();
			break;
		default:
			break;	
	}
	return choice;
}

/*displayMap*/
void Grid::displayMap(){
	//ClearScreen();
	struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
	for (int x = 0; x < w.ws_row; ++x){
		for (int y = 0; y < w.ws_col; ++y)
			cout << map[x][y];
		cout << endl;
	}
}

void Grid::ClearScreen()
    {
    cout << string( 100, '\n' );
    }
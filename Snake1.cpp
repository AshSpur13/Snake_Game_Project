#include "Snake.h"

int dir = -1;
int score = 0;
int snakeHeadPositionX = 10;
int snakeHeadPositionY = 10;

int fruitPositionX = 7;
int fruitPositionY = 15;

bool gameOver = false;

void Logic() {

	switch (dir) {
	case 0:
		snakeHeadPositionY--;
		break;
	case 1:
		snakeHeadPositionX--;
		break;
	case 2:
		snakeHeadPositionY++;
		break;
	case 3:
		snakeHeadPositionX++;
		break;
	}
	if (snakeHeadPositionX <= 0 || snakeHeadPositionX >= width - 1 || snakeHeadPositionY < 0 || snakeHeadPositionY >= height)
		gameOver = true;
	else if (snakeHeadPositionX == fruitPositionX && snakeHeadPositionY == fruitPositionY) {
		score++;
		fruitPositionX = rand() % width;
		fruitPositionY = rand() % height;
	}
}
void Input() {

	if (_kbhit()) {
		switch (_getch()) {
		case 'w': 
			dir = (dir == 2) ? dir : 0;
			break;
		case 'a':
			dir = (dir == 3) ? dir : 1;
			break;
		case 's':
			dir = (dir == 0) ? dir : 2;
			break;
		case 'd':
			dir = (dir == 1) ? dir : 3;
			break;
		case 'x':
			gameOver = true;
			break;
		}
		
	}
}
void DisplaySnakeBoard() {
	system("cls");
	
	for (int i = 0; i < width; i++) 
		cout << "*";	
	cout << endl;

	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			if (j == 0 || j == width - 1)
				cout << '*';
			else if (snakeHeadPositionX == j && snakeHeadPositionY == i) {
				cout << 'S';
			}
			else if (fruitPositionX == j && fruitPositionY == i)
				cout << 'o';
			else
				cout << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) 
		cout << "*";	
	cout << endl;
	cout << "Score: " << score << endl;

}


extern bool gameOver;

int main() {
	system("Color 0B");
	while (!gameOver) {
		DisplaySnakeBoard();
		Input();
		Logic();
	}

	return 0;
}
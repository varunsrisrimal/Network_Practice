#pragma once
#include <Windows.h>
class Game
{
	struct Ball
	{
		COORD ballPos;
		int direction; //0 - up left, 1- down left. 2-up right 3-down right
	};
public:
	Game();
	~Game();
	COORD dir[4];
	void SetBallPosition();
	void play();
	void print1(int prevY,int newY);
	void print2(int prevY, int newY);
	void UpdateBall();
	bool CheckBallConstraints();
	Ball ball;
	int paddle_posX, paddle_posY, paddle_posX2, paddle_posY2, maxBottom;
	int score1=0, score2=0;
};


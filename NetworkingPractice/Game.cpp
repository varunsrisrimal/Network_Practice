#include "Game.h"
#include <iostream>
#include <time.h>

using namespace std;

Game::Game()
{
	srand((unsigned int(time(NULL))));
	ball.ballPos.X = rand() % 50 + 50;
	ball.ballPos.Y = rand() % 15 + 20;
	ball.direction = rand() % 4 + 1;
	paddle_posY = 0;
	paddle_posX = 0;
	paddle_posY2 = 0;
	paddle_posX2 = 119;
	maxBottom = 38;

	dir[0] = { -1,-1 };
	dir[1] = { -1,+1 };
	dir[2] = { +1,-1 };
	dir[3] = { +1,+1 };


	print1(paddle_posY, paddle_posY);
	print2(paddle_posY2, paddle_posY2);

}


Game::~Game()
{
}

void Game::play()
{

	while (true)
	{
		UpdateBall();
		if (GetAsyncKeyState('W') & 0x0001)
		{
			int temp = paddle_posY;
			paddle_posY -= 1;
			if (paddle_posY < 0)
				paddle_posY = 0;
			print1(temp, paddle_posY);
		}
		else if (GetAsyncKeyState('S') & 0x0001)
		{
			int temp = paddle_posY;
			paddle_posY += 1;
			if (paddle_posY + 4 > maxBottom)
				paddle_posY = maxBottom - 4;
			print1(temp, paddle_posY);
		}
		if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			int temp = paddle_posY2;
			paddle_posY2 -= 1;
			if (paddle_posY2 < 0)
				paddle_posY2 = 0;
			print2(temp, paddle_posY2);
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			int temp = paddle_posY2;
			paddle_posY2 += 1;
			if (paddle_posY2 + 4 > maxBottom)
				paddle_posY2 = maxBottom - 4;
			print2(temp, paddle_posY2);
		}
		if (GetAsyncKeyState(VK_SHIFT) & 0x0001)
			break;
		Sleep(100);
	}
	std::cout << "\n";
	system("pause");
}

void Game::print1(int prevY, int newY)
{
	if (prevY > newY)
	{
		COORD p = { (short)paddle_posX, (short)prevY + 3 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		std::cout << " ";
		p = { (short)paddle_posX, (short)newY };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		std::cout << "]";
	}
	else if (prevY < newY)
	{
		COORD p = { (short)paddle_posX, (short)prevY };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		std::cout << " ";
		p = { (short)paddle_posX, (short)newY + 3 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		std::cout << "]";
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			COORD p = { (short)paddle_posX, short(paddle_posY + i) };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
			std::cout << "]";
		}
	}
}

void Game::print2(int prevY, int newY)
{
	if (prevY > newY)
	{
		COORD p = { (short)paddle_posX2, (short)prevY + 3 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		std::cout << " ";
		p = { (short)paddle_posX2, (short)newY };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		std::cout << "[";
	}
	else if (prevY < newY)
	{
		COORD p = { (short)paddle_posX2, (short)prevY };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		std::cout << " ";
		p = { (short)paddle_posX2, (short)newY + 3 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
		std::cout << "[";
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			COORD p = { (short)paddle_posX2, short(paddle_posY2 + i) };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
			std::cout << "[";
		}
	}
}
void Game::UpdateBall()
{
	COORD tempPos = ball.ballPos;
	while (true)
	{
		ball.ballPos.X += dir[ball.direction].X;
		ball.ballPos.Y += dir[ball.direction].Y;
		if (CheckBallConstraints())
			break;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tempPos);
	std::cout << " ";

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ball.ballPos);
	std::cout << "B";

}

bool Game::CheckBallConstraints()
{
	srand((unsigned int(time(NULL))));
	if (ball.ballPos.X <= 0)
	{
		ball.ballPos.X -= dir[ball.direction].X;
		ball.ballPos.Y -= dir[ball.direction].Y;
		if (ball.direction == 1)
			ball.direction = 3;
		else
			ball.direction = 2;
		return false;
	}
	else if (ball.ballPos.X >= 119)
	{
		ball.ballPos.X -= dir[ball.direction].X;
		ball.ballPos.Y -= dir[ball.direction].Y;
		if (ball.direction == 3)
			ball.direction = 1;
		else
			ball.direction = 0;
		return false;
	}
	else if (ball.ballPos.Y <= 0)
	{
		ball.ballPos.X -= dir[ball.direction].X;
		ball.ballPos.Y -= dir[ball.direction].Y;
		if (ball.direction == 2)
			ball.direction = 3;
		else
			ball.direction = 1;
		return false;
	}
	else if (ball.ballPos.Y >= 38)
	{
		ball.ballPos.X -= dir[ball.direction].X;
		ball.ballPos.Y -= dir[ball.direction].Y;
		if (ball.direction == 3)
			ball.direction = 2;
		else
			ball.direction = 0;
		return false;
	}
	return true;
}

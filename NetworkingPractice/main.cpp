#include <iostream>
#include <stdio.h>
#include "Server.h"
#include "Client.h"
#include "Game.h"
#include <thread>
using namespace std;

#define WIDTH 120
#define HEIGHT 40

void serverLoop();
void clientLoop();

void SetWindowSize(int columns, int rows);
void SetBufferSize(int columns, int rows);

Server * server;
Client * client;
HANDLE 	out = GetStdHandle(STD_OUTPUT_HANDLE);

void main()
{
	/*server = new Server;
	client = new Client;
	thread serverThread = thread(serverLoop);
	thread clientThread = thread(clientLoop);*/
	SetWindowSize(WIDTH, HEIGHT);
	SetBufferSize(WIDTH, HEIGHT);
	Game h;
	h.play();


}

void serverLoop()
{
	while (true)
	{
	}

}

void clientLoop()
{
	while (true)
	{

	}
}

void SetWindowSize(int columns, int rows)
{
	COORD c = GetLargestConsoleWindowSize(out);
	if (columns < 1 || columns > c.X)
		columns = c.X;
	if (rows < 1 || rows > c.Y)
		rows = c.Y;

	SMALL_RECT dim = { 0, 0, columns - 1, rows - 1 };
	SetConsoleWindowInfo(out, TRUE, &dim);
}

void SetBufferSize(int columns, int rows)
{
	COORD c = { columns, rows };
	SetConsoleScreenBufferSize(out, c);
}

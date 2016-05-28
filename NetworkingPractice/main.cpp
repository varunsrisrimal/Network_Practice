#include <iostream>
#include <stdio.h>
#include "Server.h"
#include "Client.h"
#include <thread>
using namespace std;

void serverLoop();
void clientLoop();

Server * server;
Client * client;

void main()
{
	server = new Server;
	client = new Client;
	thread serverThread = thread(serverLoop);
	thread clientThread = thread(clientLoop);

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

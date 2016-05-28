#include "NetworkProtocols.h"

int NetworkProtocols::initialize()
{
	WSADATA data;
	return WSAStartup(MAKEWORD(2, 2), &data);
}


NetworkProtocols::NetworkProtocols()
{
}


NetworkProtocols::~NetworkProtocols()
{
}

int NetworkProtocols::sendMessage(SOCKET socket, char* buffer, int messageSize)
{
	return send(socket, buffer, messageSize, 0);
}
int NetworkProtocols::recvMessage(SOCKET socket, char* buffer, int messageSize)
{
	return recv(socket, buffer, messageSize, 0);
}

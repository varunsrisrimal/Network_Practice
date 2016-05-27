#pragma once
#include <winsock2.h>
#include <Windows.h>
#pragma comment (lib, "Ws2_32.lib")
class NetworkProtocols
{
public:
	NetworkProtocols();
	~NetworkProtocols();

	int sendMessage(SOCKET socket, char* buffer, int messageSize);
	int recvMessage(SOCKET socket, char* buffer, int messageSize);

};


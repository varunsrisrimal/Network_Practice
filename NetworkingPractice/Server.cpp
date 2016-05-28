#include "Server.h"
#include <iostream>


Server::Server()
{
	int result = initialize();
	if (result != 0)
	{
		std::cout << "Failed: " << result;
		system("pause");
		exit(1);
	}
	else
	{
		if (setup())
		{
			system("pause");
			exit(1);
		}
	}

	for (int i = 0; i < MAX_CLIENTS; i++)
	{
		client[i].id = -1;
	}
}


Server::~Server()
{
}

int Server::setup()
{
	struct addrinfo *result = NULL, hint;

	ZeroMemory(&hint, sizeof(hint));
	hint.ai_family = AF_UNSPEC;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_protocol = IPPROTO_TCP;

	if (getaddrinfo(NULL, DEFAULT_PORT, &hint, &result) != 0)
	{
		std::cout << "Getaddrinfo failed withe error" << WSAGetLastError();
		WSACleanup();
		return 0;
	}

	soc = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	
	if (soc == INVALID_SOCKET)
	{
		std::cout << "Socket failed: " << WSAGetLastError();
		WSACleanup();
		return 0;
	}

	unsigned long value = 1;

	if (ioctlsocket(soc, FIONBIO, &value) == SOCKET_ERROR)
	{
		std::cout << "ioctlsocket failed";
		closesocket(soc);
		WSACleanup();
		return 0;
	}

	if (bind(soc, result->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR)
	{
		std::cout<<"Bind failed: ", WSAGetLastError();
		closesocket(soc);
		WSACleanup();
		return 0;
	}

	if (listen(soc, SOMAXCONN) < 0)
	{
		std::cout << "Listen failed: " << WSAGetLastError();
		return 0;
	}

	return 1;

}
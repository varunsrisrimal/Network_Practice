#include "Client.h"
#include <iostream>



Client::Client()
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
}

Client::~Client()
{
}

int Client::setup()
{
	struct addrinfo *result = NULL, hint;

	ZeroMemory(&hint, sizeof(hint));
	hint.ai_family = AF_UNSPEC;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_protocol = IPPROTO_TCP;

	if (getaddrinfo("127.0.0.1", DEFAULT_PORT, &hint, &result) != 0)
	{
		std::cout << "Getaddrinfo failed withe error" << WSAGetLastError();
		WSACleanup();
		return 0;
	}

	struct addrinfo *ptr = result;

	do
	{
		soc = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (soc == INVALID_SOCKET)
		{
			std::cout << "Socket failed with error:" << WSAGetLastError();
			WSACleanup();
			system("pause");
			exit(1);
		}

		if (connect(soc, ptr->ai_addr,(int) ptr->ai_addrlen) == 0)
		{
			std::cout << "Connected to Server";
			break;
		}
		else
		{
			closesocket(soc);
			soc = INVALID_SOCKET;
			ptr = ptr->ai_next;
		}
	} while (ptr != NULL);

	if (soc == INVALID_SOCKET)
		return 0;
	
	unsigned long value = 1;

	if (ioctlsocket(soc, FIONBIO, &value) == SOCKET_ERROR)
	{
		std::cout<<"ioctlsocket failed";
		closesocket(soc);
		WSACleanup();
		return 0;
	}
	return 1;

}

#pragma once
#include "NetworkProtocols.h"
#include <Ws2tcpip.h>

#define MAX_CLIENTS 4
#define DEFAULT_PORT "100"

class Server :
	public NetworkProtocols
{
	SOCKET soc;

	struct Client_Struct
	{
		int id;
		SOCKET client;
	};

	Client_Struct client[MAX_CLIENTS];
public:
	int setup();
	Server();
	~Server();
};


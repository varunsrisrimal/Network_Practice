#pragma once
#include "NetworkProtocols.h"
#include <Ws2tcpip.h>

#define DEFAULT_PORT "100"

class Client :
	public NetworkProtocols
{
	SOCKET soc;
public:
	int setup();
	void update();
	Client();
	~Client();
};


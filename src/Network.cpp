/*             .-'''''-.
             .'         `.
            :             :   File       : Network.cpp
           :               :  Creation   : 2015-05-21 01:08:12
           :      _/|      :  Last Edit  : 2015-05-21 01:27:36
            :   =/_/      :   Author     : nsierra-   
             `._/ |     .'    Mail       : nsierra-@student.42.fr  
          (   /  ,|...-'
           \_/^\/||__
        _/~  `""~`"` \_
     __/  -'/  `-._ `\_\__
   /jgs  /-'`  `\   \  \-*/

#include "Network.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

Network::Network(unsigned int port, std::string hostName) :
	_hostName(hostName),
	_port(port),
	_connected(false)
{
	_connect();
}

Network::Network(Network const & src)
{
	*this = src;
}

Network::~Network(void)
{
	if (_connected)
		close(_socket_connect);
}

Network	&Network::operator=(Network const & rhs)
{
	if (this != &rhs)
	{
		_hostName = rhs._hostName;
		_port = rhs._port;
		_connected = rhs._connected;
		_socket_connect = rhs._socket_connect;
		_sockaddr_connect = rhs._sockaddr_connect;
		_sockaddr_len = rhs._sockaddr_len;
	}
	return *this;
}

void	Network::_initConnection(void)
{
	if ((_socket_connect = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		std::cout << "Socket creation error !" << std::endl;
		return ;
	}
	_sockaddr_connect.sin_family = AF_INET;
    _sockaddr_connect.sin_port = htons(_port);
	_sockaddr_connect.sin_addr.s_addr = inet_addr(_hostName.c_str());
	bzero(&(_sockaddr_connect.sin_zero), 8);
	_sockaddr_len = sizeof(_sockaddr_connect);
}

void	Network::_connect(void)
{
	_initConnection();
	if(connect(_socket_connect, (struct sockaddr *)&_sockaddr_connect, _sockaddr_len) < 0)
		std::cout << "Socket connection error !\n" << std::endl;
	else
		_connected = true;
}

int		Network::send(const std::string &message)
{
	if (_connected)
		return write(_socket_connect, message.c_str(), message.size());
	std::cout << "Couldn't send message \"" << message << "\"" << std::endl;
	return -1;
}

bool	Network::isConnected(void) { return _connected; }

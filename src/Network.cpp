//               .-'''''-.
//             .'         `.
//            :             :        File       : Network.cpp
//           :               :       Creation   : 2015-05-21 01:08:12
//           :      _/|      :       Last Edit  : 2015-05-21 03:20:07
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs  /-'`  `\   \  \-

#include "Network.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <strings.h>
#include <string.h>

const size_t	Network::BUFF_SIZE = 2048;

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
	_close();
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
	if (connect(_socket_connect, (struct sockaddr *)&_sockaddr_connect, _sockaddr_len) < 0)
		std::cout << "Socket connection error !\n" << std::endl;
	else
		_connected = true;
}

void	Network::_close(void)
{
	if (_connected)
		close(_socket_connect);
	_connected = false;
}

std::string		Network::recieve(void)
{
	ssize_t		ret;
	char		buf[BUFF_SIZE] = { '\0' };

	ret = recv(_socket_connect, buf, BUFF_SIZE - 1, 0);
	switch (ret)
	{
		case -1:
			std::cout  << strerror(errno) << std::endl;
			break ;
		case 0:
			_close();
			break ;
		default:
			return buf;
	}
	return "ko";
}

std::string		Network::send(std::string &message)
{
	if (_connected)
	{
		if (write(_socket_connect, (message + "\n").c_str(), message.size()) < 0)
		{
			std::cout << strerror(errno) << std::endl;
			return "ko";
		}
		return recieve();
	}
	std::cout
		<< "Couldn't send message \"" << message
		<< "\" ! Not connected." << std::endl
	;
	return "ko";
}

bool			Network::isConnected(void) { return _connected; }
std::string		Network::getHostName(void) { return _hostName; }
unsigned int	Network::getPort(void) { return _port; }

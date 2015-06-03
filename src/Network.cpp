//               .-'''''-.
//             .'         `.
//            :             :        File       : Network.cpp
//           :               :       Creation   : 2015-05-21 01:08:12
//           :      _/|      :       Last Edit  : 2015-06-04 01:12:09
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs  /-'`  `\   \  \-

#include "Network.hpp"
#include "ErrorMsg.hpp"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <string>
#include <strings.h>
#include <string.h>
#include <sys/socket.h>

const size_t		Network::BUFF_SIZE = 2048;
const std::string	Network::MSG_SUCCESS = "ok\n";
const std::string	Network::MSG_FAILURE = "ko\n";
const std::string	Network::MSG_DEATH = "mort\n";
const std::string	Network::MSG_BROADCAST = "message ";
const std::string	Network::MSG_ELEVATION = "elevation en cours\n";
const std::string	Network::MSG_CURRENT_LVL = "niveau actuel : ";
const std::string	Network::MSG_WELCOME = "BIENVENUE\n";

Network::Network(Client *client, unsigned int port, std::string hostName) :
	_client(client),
	_hostName(hostName),
	_port(port),
	_connected(false)
{
	_connect();
	if (_connected)
		std::cout << getpid() << " dit " << "Connected to server." << std::endl;
}

Network::Network(Network const & src) :
	_client(src._client)
{
	*this = src;
}

Network::~Network(void)
{
	this->close();
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
		std::cout << E_SOCKET_CREATION << std::endl;
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
		std::cout << E_SOCKET_CONNECTION << std::endl;
	else
		_connected = true;
}

void	Network::close(void)
{
	if (_connected)
		::close(_socket_connect);
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
			this->close();
			break ;
		default:
			_client->printDebug(buf);

			if (!strncmp(buf, MSG_DEATH.c_str(), 5))
				_client->hasDied();
			else if (!strncmp(buf, MSG_BROADCAST.c_str(), 7))
			{
				_client->recieveBroadcast(buf);
				_client->printDebug("Broadcast recieved ! Recieving again...");
				return recieve();
			}
			return buf;
	}
	return MSG_FAILURE;
}

std::string		Network::send(const std::string &message)
{
	if (_connected)
	{
		std::string		toSend = message;

		toSend += "\n";
		_client->printDebug(message);
		if (::send(_socket_connect, toSend.c_str(), toSend.size(), 0) < 0)
		{
			std::cout << strerror(errno) << std::endl;
			return MSG_FAILURE;
		}
		return recieve();
	}
	std::cout
		<< "Couldn't send message \"" << message
		<< "\" ! Not connected." << std::endl
	;
	exit(EXIT_FAILURE);
	return MSG_FAILURE;
}

bool			Network::isConnected(void) { return _connected; }
std::string		Network::getHostName(void) { return _hostName; }
unsigned int	Network::getPort(void) { return _port; }

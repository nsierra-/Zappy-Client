//               .-'''''-.
//             .'         `.
//            :             :        File       : Client.cpp
//           :               :       Creation   : 2015-05-21 00:44:59
//           :      _/|      :       Last Edit  : 2015-05-23 03:55:33
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs  /-'`  `\   \  \-

#include "Client.hpp"
#include "ErrorMsg.hpp"
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <iostream>
#include <regex>

const std::regex	Client::_serverInfosFormat("(\\d+)\\n(\\d+) (\\d+)\\n");

Client::Client(unsigned int port, std::string teamName, std::string hostName) :
	_teamName(teamName),
	_network(new Network(port, hostName))
{

}

Client::Client(Client const & src) :
	_teamName(src._teamName)
{
	*this = src;
}

Client::~Client(void)
{
  delete _network;
}

Client	&Client::operator=(Client const & rhs)
{
	if (this != &rhs)
		_network = new Network(*(rhs._network));
	return *this;
}

bool	Client::loop(void)
{
	std::string msg;

	_loadServerInfos(_sendTeamInfo());
	while (42)
	{
		msg = _network->send("connect_nbr\n");
		std::cout << msg << std::endl;
		if (msg == "mort\n")
			exit(0);
		if (atoi(msg.c_str()))
		{
			std::stringstream port;
			port << _network->getPort();
			char * arg[7] = {(char *)"./client", (char *)"-n", (char *)_teamName.c_str(), (char *)"-p", (char *)port.str().c_str(), (char *)"-h", (char *)_network->getHostName().c_str()};
			execve("./client",arg, NULL);
		}
	}
	return true;
}

void			Client::_forkstem(void)
{
	pid_t		pid = fork();

	if (pid == 0)
	{
		std::stringstream	cmd;

		cmd
			<< "./client -n " << _teamName
			<< " -p " << _network->getPort()
			<< " -h " << _network->getHostName()
		;
		system(cmd.str().c_str());
	}
	else if (pid > 0)
		return ;
	else
	{
		std::cout << E_FORK << std::endl;
		exit(EXIT_FAILURE);
	}
}

void			Client::_loadServerInfos(const std::string &infos)
{
	std::smatch	sm;
	std::string	tmp;

	std::regex_match(infos, sm, _serverInfosFormat);
	if (sm.size() != 4)
	{
		std::cout << E_UNUSUAL_SERVER_BEHAVIOR << std::endl;
		exit(EXIT_FAILURE);
	}
	tmp = sm[1],  _availableConnections = strtol(tmp.c_str(), NULL, 10);
	tmp = sm[2],  _mapX = strtol(tmp.c_str(), NULL, 10);
	tmp = sm[3],  _mapY = strtol(tmp.c_str(), NULL, 10);
}

std::string    Client::_sendTeamInfo(void) const
{
	std::string     msg(_network->recieve());

	if (msg == "BIENVENUE\n")
		return _network->send(_teamName + "\n");
	else
	{
		std::cout << E_UNUSUAL_SERVER_BEHAVIOR << std::endl;
		exit(EXIT_FAILURE);
	}
}
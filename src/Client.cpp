//               .-'''''-.
//             .'         `.
//            :             :        File       : Client.cpp
//           :               :       Creation   : 2015-05-21 00:44:59
//           :      _/|      :       Last Edit  : 2015-05-29 17:10:35
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
#include <fstream>
#include <iostream>
#include <regex>

const std::regex	Client::_serverInfosFormat("(\\d+)\\n(\\d+) (\\d+)\\n");

std::map<Client::eDirection, std::string>	Client::_directionMap = 
	{
		{ UP, "avance\n" },
		{ TURN_LEFT, "gauche\n" },
		{ TURN_RIGHT, "droite\n" }
	}
;


Client::Client(unsigned int port, std::string teamName, std::string hostName) :
	_teamName(teamName),
	_network(new Network(port, hostName)),
	_level(1)
{

	std::stringstream name;
	name << "debug/" << getpid();
	_ofs.open(name.str().c_str());

	_inventory["nourriture"] = 10;
}

Client::Client(Client const & src) :
_teamName(src._teamName)
{
	*this = src;
}

Client::~Client(void)
{
	_ofs.close();
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
		if (msg == "mort\n")
			exit(0);
		if (strtol(_network->send("connect_nbr\n").c_str(), NULL, 10))
			_forkstem();
		else 
		{
			_ia();
			msg = _network->recieve();
			_ofs << getpid() << " recoit " << msg << std::endl;
		}
	}
	return true;
}

void	Client::_ia(void)
{

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
		_ofs << E_FORK << std::endl;
		exit(EXIT_FAILURE);
	}
}

void					Client::_move(enum eDirection dir)
{
	_ofs << _directionMap[dir] << std::endl;
	_ofs << _network->send(_directionMap[dir]) << std::endl;
}

void					Client::_see(void)
{
	std::string			data;

	_ofs << "voir" << std::endl;
	data = _network->send("voir\n");
	_ofs << data << std::endl;
}

void					Client::_updateInventory(const std::string &obj, int qty)
{
	_inventory[obj] += qty;
}

void					Client::_updateInventory(void)
{
	std::string			data;

	_ofs << "inventaire" << std::endl;
	data = _network->send("inventaire\n");
	_ofs << data << std::endl;
}

void					Client::_take(const std::string & obj)
{
	std::string			message = "prendre ";
	std::string			data;

	message += obj + "\n";
	_ofs << message << std::endl;
	data = _network->send(message);
	_ofs << data << std::endl;

	if (data == "ok\n")
		_updateInventory(obj, 1);
}

void					Client::_drop(const std::string & obj)
{
	std::string			message = "prendre ";
	std::string			data;

	message += obj + "\n";
	_ofs << message << std::endl;
	data = _network->send(message);
	_ofs << data << std::endl;

	if (data == "ok\n")
		_updateInventory(obj, -1);
}

void					Client::_expulse(void)
{
	std::string			data;

	_ofs << "expulse" << std::endl;
	data = _network->send("expulse\n");
	_ofs << data << std::endl;
}

void					Client::_broadcast(const std::string & msg)
{
	_ofs << msg << std::endl;
	_ofs << _network->send(msg) << std::endl;
}

void					Client::_incantation(void)
{
	std::string			data;

	_ofs << "incantation" << std::endl;
	data = _network->send("incantation\n");
	_ofs << data << std::endl;

	if (data == "elevation en cours\n")
	{
		data = _network->recieve();
		_ofs << data << std::endl;
		_level++;
	}
}

void					Client::_egg(void)
{
	_ofs << "fork" << std::endl;
	_ofs << _network->send("fork\n") << std::endl;	
}

void			Client::_loadServerInfos(const std::string &infos)
{
	std::smatch	sm;
	std::string	tmp;

	_ofs << infos << std::endl;
	std::regex_match(infos, sm, _serverInfosFormat);
	if (sm.size() != 4)
	{
		_ofs << E_UNUSUAL_SERVER_BEHAVIOR << std::endl;
		exit(EXIT_FAILURE);
	}
	tmp = sm[1],  _availableConnections = strtol(tmp.c_str(), NULL, 10);
	tmp = sm[2],  _mapX = strtol(tmp.c_str(), NULL, 10);
	tmp = sm[3],  _mapY = strtol(tmp.c_str(), NULL, 10);
}

std::string    Client::_sendTeamInfo(void)
{
	std::string     msg(_network->recieve());

	_ofs << msg << std::endl;
	if (msg == "BIENVENUE\n")
		return _network->send(_teamName + "\n");
	else
	{
		_ofs << E_UNUSUAL_SERVER_BEHAVIOR << std::endl;
		exit(EXIT_FAILURE);
	}
}
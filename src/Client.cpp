//               .-'''''-.
//             .'         `.
//            :             :        File       : Client.cpp
//           :               :       Creation   : 2015-05-21 00:44:59
//           :      _/|      :       Last Edit  : 2015-05-29 21:30:36
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
#include <ctime>
#include <locale>

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
	_network(new Network(this, port, hostName)),
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
		if (strtol(_network->send("connect_nbr\n").c_str(), NULL, 10))
		{
			printDebug("FORKSTEN");
			_forkstem();
		}
		else 
		{
			_ia();
			
			_network->recieve();
		}
	}
	return true;
}

void	Client::printDebug(const std::string & msg)
{
	std::locale::global(std::locale(""));
    std::time_t t = std::time(NULL);

	char	mbstr[100] = { '\0' };

	std::strftime(mbstr, sizeof(mbstr) - 1, "%T", std::localtime(&t));
	_ofs << "[" << mbstr << "] " << getpid() << " " << msg << std::endl;
}

void	Client::hasDied(void)
{
	printDebug("Client is dead.");
	_network->close();
	exit(EXIT_SUCCESS);
}

void	Client::recieveBroadcast(const std::string & msg)
{
	//regex parse msg
	//	 message
	//	 case
	//	 content
	(void)msg;
		// switch (atoi(case))
		// {
		// 	case 1:
		// 		_move(UP);
		// 		break;
		// 	case 2:
		// 		break;
		// 	case 3:
		// 		break;
		// 	case 4:
		// 		break;
		// 	case 5:
		// 		break;
		// 	case 6:
		// 		break;
		// 	case 7:
		// 		break;
		// 	case 8:
		// 		break;
		// 	default:
		// 		break;
		// }
}

void	Client::_ia(void)
{
		if (_compos(_level) && _inventory["nourriture"] > 4)
		{
			if (_level > 1)
				_search();
			_incantation();			
		}
		else
			_composFind(_level);
		_playMove();
}

void			Client::_playMove(void)
{

}

void			Client::_search(void)
{
	// std::string dir;
	// int 		players;

	// while (players != nb_player)
	// {
	// 	_broadcast("incantation level " + _level + "\n");
	// 	dir = _network->recieve();

	// }
}

void			Client::_composFind(int level)
{
	(void)level;
	//if nourriture take nourriture
	//take compos for all level
}

int				Client::_compos(int level)
{
	if (level == 1)
	{
		if (_inInventory("linemate"))
		{
			_drop("linemate");
			return 1;
		}
		_see();
		if (_fov.find("linemate", 0))
			return 1;
		else
			return 0;
	}
	//cmp compos needed vs inventory
	return 0;
}

void			Client::_forkstem(void)
{
	pid_t		pid = fork();

	if (pid == 0)
	{
		_network->close();
		Client	c(_network->getPort(), _teamName, _network->getHostName());
		c.loop();
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
	printDebug("voir");
	_fov = _network->send("voir\n");
}

void					Client::_updateInventory(const std::string &obj, int qty)
{
	_inventory[obj] += qty;
}

int						Client::_inInventory(const std::string &name)
{
	if (_inventory[name] > 0)
		return 1;
	return 0;
}

void					Client::_updateInventory(void)
{
	std::string			data;

	printDebug("inventaire");
	data = _network->send("inventaire\n");
}

void					Client::_take(const std::string & obj)
{
	std::string			message = "prendre ";
	std::string			data;

	message += obj + "\n";
	printDebug(message);
	data = _network->send(message);

	if (data == "ok\n")
		_updateInventory(obj, 1);
}

void					Client::_drop(const std::string & obj)
{
	std::string			message = "prendre ";
	std::string			data;

	message += obj + "\n";
	printDebug(message);
	data = _network->send(message);

	if (data == "ok\n")
		_updateInventory(obj, -1);
}

void					Client::_expulse(void)
{
	std::string			data;

	printDebug("expulse");
	data = _network->send("expulse\n");
}

void					Client::_broadcast(const std::string & msg)
{
	printDebug(msg);
	printDebug(_network->send(msg));
}

void					Client::_incantation(void)
{
	std::string			data;

	printDebug("incantation");
	data = _network->send("incantation\n");

	if (data == "elevation en cours\n")
	{
		data = _network->recieve();
		_level++;
	}
}

void					Client::_egg(void)
{
	printDebug("fork");
	printDebug(_network->send("fork\n"));
}

void			Client::_loadServerInfos(const std::string &infos)
{
	std::smatch	sm;
	std::string	tmp;

	std::regex_match(infos, sm, _serverInfosFormat);
	if (sm.size() != 4)
	{
		printDebug(E_UNUSUAL_SERVER_BEHAVIOR);
		exit(EXIT_FAILURE);
	}
	tmp = sm[1],  _availableConnections = strtol(tmp.c_str(), NULL, 10);
	tmp = sm[2],  _mapX = strtol(tmp.c_str(), NULL, 10);
	tmp = sm[3],  _mapY = strtol(tmp.c_str(), NULL, 10);
}

std::string    Client::_sendTeamInfo(void)
{
	std::string     msg(_network->recieve());

	if (msg == "BIENVENUE\n")
		return _network->send(_teamName + "\n");
	else
	{
		printDebug(E_UNUSUAL_SERVER_BEHAVIOR);
		exit(EXIT_FAILURE);
	}
}
//               .-'''''-.
//             .'         `.
//            :             :        File       : Client.cpp
//           :               :       Creation   : 2015-05-21 00:44:59
//           :      _/|      :       Last Edit  : 2015-05-21 03:17:22
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs  /-'`  `\   \  \-

#include "Client.hpp"
#include <iostream>

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
    {
        _network = new Network(*(rhs._network));
	}
	return *this;
}

bool	Client::loop(void)
{
    _sendTeamInfo();
    while (42)
    {
    }
    return true;
}

void    Client::_sendTeamInfo(void)4242
{
    std::string     msg(_network->recieve());

    std::cout << "Msg -> " << msg << std::endl;
    if (msg == "BIENVENUE\n")
    {
        std::cout << _network->send(_teamName) << std::endl;
    }
}
/*             .-'''''-.
             .'         `.
            :             :   File       : Client.cpp
           :               :  Creation   : 2015-05-21 00:44:59
           :      _/|      :  Last Edit  : 2015-05-21 01:31:10
            :   =/_/      :   Author     : nsierra-   
             `._/ |     .'    Mail       : nsierra-@student.42.fr  
          (   /  ,|...-'
           \_/^\/||__
        _/~  `""~`"` \_
     __/  -'/  `-._ `\_\__
   /jgs  /-'`  `\   \  \-*/

#include "Client.hpp"

Client::Client(unsigned int port, std::string teamName, std::string hostName) :
	_teamName(teamName),
    _network(new Network(port, hostName))
{

}

Client::Client(Client const & src)
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

	}
	return *this;
}

bool	Client::loop(void)
{
    _network->send("lel");
    _network->send("voir");

    return true;
}

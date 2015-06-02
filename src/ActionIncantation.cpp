#include "ActionIncantation.hpp"

ActionIncantation::ActionIncantation(Client *client) :
	_client(client)
{

}

ActionIncantation::ActionIncantation(ActionIncantation const &model)
{
	*this = model;
}

ActionIncantation::~ActionIncantation()
{

}

std::string	ActionIncantation::toString() const
{
	return "ActionIncantation";
}

ActionIncantation&	ActionIncantation::operator=(ActionIncantation const &copy)
{
	if (this != &copy)
		_client = copy._client;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionIncantation const &i)
{
	o << i.toString();
	return o;
}

void	ActionIncantation::execute(Network &network)
{
	std::string			data;

	data = network.send("incantation\n");

	if (data == "elevation en cours\n")
	{
		data = network.recieve();
		_client->setLevel(_client->getLevel() + 1);
	}
}
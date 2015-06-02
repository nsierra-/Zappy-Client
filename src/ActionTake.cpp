#include "ActionTake.hpp"

ActionTake::ActionTake(const std::string &obj, Client *client) :
	_obj(obj),
	_client(client)
{

}

ActionTake::ActionTake(ActionTake const &model)
{
	*this = model;
}

ActionTake::~ActionTake()
{

}

std::string	ActionTake::toString() const
{
	return "ActionTake";
}

ActionTake&	ActionTake::operator=(ActionTake const &copy)
{
	if (this != &copy)
	{
		_obj = copy._obj;
		_client = copy._client;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionTake const &i)
{
	o << i.toString();
	return o;
}

void	ActionTake::execute(Network &network)
{
	std::string			message = "prendre ";
	std::string			data;

	message += _obj + "\n";
	data = network.send(message);

	if (data == "ok\n")
		_client->_updateInventory(_obj, 1);
}
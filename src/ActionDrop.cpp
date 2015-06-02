#include "ActionDrop.hpp"
#include <sstream>

ActionDrop::ActionDrop(const std::string &obj, Client *client) :
	_object(obj),
	_client(client)
{

}

ActionDrop::ActionDrop(ActionDrop const &model) :
	_object(model._object)
{
	*this = model;
}

ActionDrop::~ActionDrop()
{

}

std::string	ActionDrop::toString() const
{
	std::stringstream	ss;

	ss
		<< "ActioDrop : " << _object
	;
	return ss.str();
}

ActionDrop&	ActionDrop::operator=(ActionDrop const &copy)
{
	if (this != &copy)
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionDrop const &i)
{
	o << i.toString();
	return o;
}

void	ActionDrop::execute(Network &network)
{
	std::string			message = "pose ";
	std::string			data;

	message += _object + "\n";
	data = network.send(message);

	if (data == "ok\n")
		_client->_updateInventory(_object, -1);
}
#include "ActionTake.hpp"

ActionTake::ActionTake(const std::string &obj, Inventory & inventory) :
	_obj(obj),
	_inventory(inventory)
{

}

ActionTake::ActionTake(ActionTake const & model) :
	_obj(model._obj),
	_inventory(model._inventory)
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

ActionTake&	ActionTake::operator=(ActionTake const & copy)
{
	if (this != &copy)
	{
		_obj = copy._obj;
		_inventory = copy._inventory;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionTake const & i)
{
	o << i.toString();
	return o;
}

int	ActionTake::execute(Network &network)
{
	std::string			message = Action::TAKE;
	std::string			data;

	message += _obj;
	data = network.send(message);

	if (data == Network::MSG_SUCCESS)
	{
		_inventory.add(_obj, 1);
		return _successIndex;
	}
	return _failIndex;
}
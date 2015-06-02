#include "ActionDrop.hpp"
#include <sstream>

ActionDrop::ActionDrop(const std::string &obj, Inventory & inventory) :
	_object(obj),
	_inventory(inventory)
{

}

ActionDrop::ActionDrop(ActionDrop const & model) :
	_object(model._object),
	_inventory(model._inventory)
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
		<< "ActionDrop : " << _object
	;
	return ss.str();
}

ActionDrop&	ActionDrop::operator=(ActionDrop const & copy)
{
	if (this != &copy)
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream & o, ActionDrop const &i)
{
	o << i.toString();
	return o;
}

void	ActionDrop::execute(Network &network)
{
	std::string			message = A_DROP;
	std::string			data;

	message += _object;
	data = network.send(message);

	if (data == "ok\n")
		_inventory.add(_object, -1);
}
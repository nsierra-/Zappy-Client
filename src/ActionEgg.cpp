#include "ActionEgg.hpp"

ActionEgg::ActionEgg()
{

}

ActionEgg::ActionEgg(ActionEgg const &model)
{
	*this = model;
}

ActionEgg::~ActionEgg()
{

}

std::string		ActionEgg::toString() const
{
	return "ActionEgg";
}

ActionEgg		&ActionEgg::operator=(ActionEgg const &copy)
{
	if (this != &copy)
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, const ActionEgg &i)
{
	o << i.toString();
	return o;
}

int				ActionEgg::execute(Network &network)
{
	std::string		ret;

	ret = network.send(EGG);

	if (ret == Network::MSG_SUCCESS)
		return _successIndex;
	return _failIndex;
}
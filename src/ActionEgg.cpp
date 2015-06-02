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

std::string	ActionEgg::toString() const
{
	return "ActionEgg";
}

ActionEgg&	ActionEgg::operator=(ActionEgg const &copy)
{
	if (this != &copy)
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionEgg const &i)
{
	o << i.toString();
	return o;
}

void	ActionEgg::execute(Network &network)
{
	network.send(A_EGG);
}
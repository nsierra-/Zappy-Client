#include "ActionSee.hpp"

ActionSee::ActionSee()
{

}

ActionSee::ActionSee(ActionSee const &model)
{
	*this = model;
}

ActionSee::~ActionSee()
{

}

std::string	ActionSee::toString() const
{
	return "ActionSee";
}

ActionSee&	ActionSee::operator=(ActionSee const &copy)
{
	if (this != &copy)
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionSee const &i)
{
	o << i.toString();
	return o;
}

void	ActionSee::execute(Network &network)
{
	network.send(SEE);
}
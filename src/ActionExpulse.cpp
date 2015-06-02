#include "ActionExpulse.hpp"

ActionExpulse::ActionExpulse()
{

}

ActionExpulse::ActionExpulse(ActionExpulse const &model)
{
	*this = model;
}

ActionExpulse::~ActionExpulse()
{

}

std::string	ActionExpulse::toString() const
{
	return "ActionExpulse";
}

ActionExpulse&	ActionExpulse::operator=(ActionExpulse const &copy)
{
	if (this != &copy)
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionExpulse const &i)
{
	o << i.toString();
	return o;
}

void	ActionExpulse::execute(Network &network)
{
	network.send("expulse\n");
}
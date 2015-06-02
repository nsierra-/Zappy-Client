#include "ActionTake.hpp"

ActionTake::ActionTake()
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
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionTake const &i)
{
	o << i.toString();
	return o;
}
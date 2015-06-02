#include "ActionIncantation.hpp"

ActionIncantation::ActionIncantation()
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
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionIncantation const &i)
{
	o << i.toString();
	return o;
}
#include "ActionMove.hpp"

ActionMove::ActionMove()
{

}

ActionMove::ActionMove(ActionMove const &model)
{
	*this = model;
}

ActionMove::~ActionMove()
{

}

std::string	ActionMove::toString() const
{
	return "ActionMove";
}

ActionMove&	ActionMove::operator=(ActionMove const &copy)
{
	if (this != &copy)
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionMove const &i)
{
	o << i.toString();
	return o;
}
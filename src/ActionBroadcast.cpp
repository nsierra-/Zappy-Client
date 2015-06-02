#include "ActionBroadcast.hpp"

ActionBroadcast::ActionBroadcast()
{

}

ActionBroadcast::ActionBroadcast(ActionBroadcast const &model)
{
	*this = model;
}

ActionBroadcast::~ActionBroadcast()
{

}

std::string	ActionBroadcast::toString() const
{
	return "ActionBroadcast";
}

ActionBroadcast&	ActionBroadcast::operator=(ActionBroadcast const &copy)
{
	if (this != &copy)
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionBroadcast const &i)
{
	o << i.toString();
	return o;
}
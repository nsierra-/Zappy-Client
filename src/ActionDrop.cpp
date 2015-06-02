#include "ActionDrop.hpp"

ActionDrop::ActionDrop()
{

}

ActionDrop::ActionDrop(ActionDrop const &model)
{
	*this = model;
}

ActionDrop::~ActionDrop()
{

}

std::string	ActionDrop::toString() const
{
	return "ActionDrop";
}

ActionDrop&	ActionDrop::operator=(ActionDrop const &copy)
{
	if (this != &copy)
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionDrop const &i)
{
	o << i.toString();
	return o;
}
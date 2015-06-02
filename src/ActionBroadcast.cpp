#include "ActionBroadcast.hpp"
#include <sstream>

ActionBroadcast::ActionBroadcast(const std::string &msg) :
	_msg(msg)
{

}

ActionBroadcast::ActionBroadcast(ActionBroadcast const &model) :
	_msg(model._msg)
{
	*this = model;
}

ActionBroadcast::~ActionBroadcast()
{

}

std::string	ActionBroadcast::toString() const
{
	std::stringstream	ss;

	ss
		<< "ActionBroadcast : " << _msg
	;
	return ss.str();
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

void	ActionBroadcast::execute(Network &network)
{
	network.send(A_BROADCAST + _msg);
}
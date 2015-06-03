#include "ActionBroadcast.hpp"
#include <sstream>

ActionBroadcast::ActionBroadcast()
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

std::string		ActionBroadcast::toString() const
{
	std::stringstream	ss;

	ss
		<< "ActionBroadcast : " << _msg
	;
	return ss.str();
}

ActionBroadcast	&ActionBroadcast::operator=(ActionBroadcast const &copy)
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

int				ActionBroadcast::execute(Network &network)
{
	std::string		ret;

	ret = network.send(BROADCAST + _msg);

	if (ret == Network::MSG_SUCCESS)
		return _successIndex;
	return _failIndex;
}

void			ActionBroadcast::setMessage(const std::string &msg)
{
	_msg = msg;
}

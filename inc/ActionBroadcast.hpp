#ifndef ACTIONBROADCAST_HEADER
#define ACTIONBROADCAST_HEADER

#include <string>
#include <iostream>
#include "Action.hpp"

class ActionBroadcast : public Action
{
public:
	ActionBroadcast(const std::string &);
	ActionBroadcast(ActionBroadcast const &);
	virtual ~ActionBroadcast();
	std::string	toString() const;

	ActionBroadcast	&operator=(ActionBroadcast const &);

	virtual int			execute(Network &);

private:
	const std::string		_msg;
};

std::ostream	&operator<<(std::ostream &o, ActionBroadcast const &i);

#endif /*ACTIONBROADCAST_HEADER*/

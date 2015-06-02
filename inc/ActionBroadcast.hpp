#ifndef ACTIONBROADCAST_HEADER
#define ACTIONBROADCAST_HEADER

#include <string>
#include <iostream>

class ActionBroadcast
{
public:
	ActionBroadcast();
	ActionBroadcast(ActionBroadcast const &);
	virtual ~ActionBroadcast();
	std::string	toString() const;

	ActionBroadcast&	operator=(ActionBroadcast const &);

	
};

std::ostream	&operator<<(std::ostream &o, ActionBroadcast const &i);

#endif /*ACTIONBROADCAST_HEADER*/
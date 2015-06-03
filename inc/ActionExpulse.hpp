#ifndef ACTIONEXPULSE_HEADER
#define ACTIONEXPULSE_HEADER

#include <string>
#include <iostream>
#include "Action.hpp"

class ActionExpulse : public Action
{
public:
	ActionExpulse();
	ActionExpulse(ActionExpulse const &);
	virtual ~ActionExpulse();
	std::string	toString() const;

	ActionExpulse	&operator=(ActionExpulse const &);

	virtual int	execute(Network &);
};

std::ostream	&operator<<(std::ostream &, ActionExpulse const &);

#endif /*ACTIONEXPULSE_HEADER*/

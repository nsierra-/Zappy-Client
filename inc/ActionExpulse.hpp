#ifndef ACTIONEXPULSE_HEADER
#define ACTIONEXPULSE_HEADER

#include <string>
#include <iostream>
#include "IAction.hpp"

class ActionExpulse : public IAction
{
public:
	ActionExpulse();
	ActionExpulse(ActionExpulse const &);
	virtual ~ActionExpulse();
	std::string	toString() const;

	ActionExpulse&	operator=(ActionExpulse const &);

	virtual int	execute(Network &network);
};

std::ostream	&operator<<(std::ostream &o, ActionExpulse const &i);

#endif /*ACTIONEXPULSE_HEADER*/

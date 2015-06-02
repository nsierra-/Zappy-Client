#ifndef ACTIONEXPULSE_HEADER
#define ACTIONEXPULSE_HEADER

#include <string>
#include <iostream>

class ActionExpulse
{
public:
	ActionExpulse();
	ActionExpulse(ActionExpulse const &);
	virtual ~ActionExpulse();
	std::string	toString() const;

	ActionExpulse&	operator=(ActionExpulse const &);

	
};

std::ostream	&operator<<(std::ostream &o, ActionExpulse const &i);

#endif /*ACTIONEXPULSE_HEADER*/
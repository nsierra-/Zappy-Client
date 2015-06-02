#ifndef ACTIONMOVE_HEADER
#define ACTIONMOVE_HEADER

#include <string>
#include <iostream>

class ActionMove
{
public:
	ActionMove();
	ActionMove(ActionMove const &);
	virtual ~ActionMove();
	std::string	toString() const;

	ActionMove&	operator=(ActionMove const &);

	
};

std::ostream	&operator<<(std::ostream &o, ActionMove const &i);

#endif /*ACTIONMOVE_HEADER*/
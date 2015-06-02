#ifndef ACTIONTAKE_HEADER
#define ACTIONTAKE_HEADER

#include <string>
#include <iostream>

class ActionTake
{
public:
	ActionTake();
	ActionTake(ActionTake const &);
	virtual ~ActionTake();
	std::string	toString() const;

	ActionTake&	operator=(ActionTake const &);

	
};

std::ostream	&operator<<(std::ostream &o, ActionTake const &i);

#endif /*ACTIONTAKE_HEADER*/
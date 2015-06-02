#ifndef ACTIONSEE_HEADER
#define ACTIONSEE_HEADER

#include <string>
#include <iostream>

class ActionSee
{
public:
	ActionSee();
	ActionSee(ActionSee const &);
	virtual ~ActionSee();
	std::string	toString() const;

	ActionSee&	operator=(ActionSee const &);

	
};

std::ostream	&operator<<(std::ostream &o, ActionSee const &i);

#endif /*ACTIONSEE_HEADER*/
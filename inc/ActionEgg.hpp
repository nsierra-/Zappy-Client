#ifndef ACTIONEGG_HEADER
#define ACTIONEGG_HEADER

#include <string>
#include <iostream>

class ActionEgg
{
public:
	ActionEgg();
	ActionEgg(ActionEgg const &);
	virtual ~ActionEgg();
	std::string	toString() const;

	ActionEgg&	operator=(ActionEgg const &);

	
};

std::ostream	&operator<<(std::ostream &o, ActionEgg const &i);

#endif /*ACTIONEGG_HEADER*/
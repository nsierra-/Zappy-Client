#ifndef ACTIONINCANTATION_HEADER
#define ACTIONINCANTATION_HEADER

#include <string>
#include <iostream>

class ActionIncantation
{
public:
	ActionIncantation();
	ActionIncantation(ActionIncantation const &);
	virtual ~ActionIncantation();
	std::string	toString() const;

	ActionIncantation&	operator=(ActionIncantation const &);

	
};

std::ostream	&operator<<(std::ostream &o, ActionIncantation const &i);

#endif /*ACTIONINCANTATION_HEADER*/
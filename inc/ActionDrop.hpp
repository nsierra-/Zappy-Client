#ifndef ACTIONDROP_HEADER
#define ACTIONDROP_HEADER

#include <string>
#include <iostream>

class ActionDrop
{
public:
	ActionDrop();
	ActionDrop(ActionDrop const &);
	virtual ~ActionDrop();
	std::string	toString() const;

	ActionDrop&	operator=(ActionDrop const &);

	
};

std::ostream	&operator<<(std::ostream &o, ActionDrop const &i);

#endif /*ACTIONDROP_HEADER*/
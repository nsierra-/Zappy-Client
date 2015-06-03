#ifndef ACTIONEGG_HEADER
#define ACTIONEGG_HEADER

#include <string>
#include <iostream>
#include "Action.hpp"

class ActionEgg : public Action
{
public:
	ActionEgg();
	ActionEgg(ActionEgg const &);
	virtual ~ActionEgg();
	std::string	toString() const;

	ActionEgg	&operator=(ActionEgg const &);

	virtual int		execute(Network &);
};

std::ostream	&operator<<(std::ostream &, ActionEgg const &);

#endif /*ACTIONEGG_HEADER*/

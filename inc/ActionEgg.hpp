#ifndef ACTIONEGG_HEADER
#define ACTIONEGG_HEADER

#include <string>
#include <iostream>
#include "IAction.hpp"

class ActionEgg : public IAction
{
public:
	ActionEgg();
	ActionEgg(ActionEgg const &);
	virtual ~ActionEgg();
	std::string	toString() const;

	ActionEgg&	operator=(ActionEgg const &);

	virtual void	execute(Network &network);
};

std::ostream	&operator<<(std::ostream &o, ActionEgg const &i);

#endif /*ACTIONEGG_HEADER*/

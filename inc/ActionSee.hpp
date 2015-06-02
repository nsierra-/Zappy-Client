#ifndef ACTIONSEE_HEADER
#define ACTIONSEE_HEADER

#include <string>
#include <iostream>
#include "IAction.hpp"

class ActionSee : public IAction
{
public:
	ActionSee();
	ActionSee(ActionSee const &);
	virtual ~ActionSee();
	std::string	toString() const;

	ActionSee&	operator=(ActionSee const &);

	virtual void	execute(Network &network);
};

std::ostream	&operator<<(std::ostream &o, ActionSee const &i);

#endif /*ACTIONSEE_HEADER*/

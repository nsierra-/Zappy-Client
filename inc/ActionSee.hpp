#ifndef ACTIONSEE_HEADER
#define ACTIONSEE_HEADER

#include <string>
#include <iostream>
#include "IAction.hpp"

class ActionSee : public IAction
{
public:
	ActionSee(Client *client);
	ActionSee(ActionSee const &);
	virtual ~ActionSee();
	std::string	toString() const;

	ActionSee&	operator=(ActionSee const &);

	virtual void	execute(Network &network);
private:
	Client			*_client;
};

std::ostream	&operator<<(std::ostream &o, ActionSee const &i);

#endif /*ACTIONSEE_HEADER*/

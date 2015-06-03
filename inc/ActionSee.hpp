#ifndef ACTIONSEE_HEADER
#define ACTIONSEE_HEADER

#include <string>
#include <iostream>
#include "Action.hpp"
#include "Client.hpp"

class Client;

class ActionSee : public Action
{
public:
	ActionSee(Client *);
	ActionSee(ActionSee const &);
	virtual ~ActionSee();
	std::string	toString() const;

	ActionSee	&operator=(ActionSee const &);

	virtual int	execute(Network &);
private:
	Client			*_client;
};

std::ostream	&operator<<(std::ostream &, ActionSee const &);

#endif /*ACTIONSEE_HEADER*/

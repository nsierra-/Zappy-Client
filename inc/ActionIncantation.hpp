#ifndef ACTIONINCANTATION_HEADER
#define ACTIONINCANTATION_HEADER

#include <string>
#include <iostream>
#include "Action.hpp"
#include "Client.hpp"

class Client;

class ActionIncantation : public Action
{
public:
	ActionIncantation(Client *);
	ActionIncantation(ActionIncantation const &);
	virtual ~ActionIncantation();
	std::string	toString() const;

	ActionIncantation &operator=(ActionIncantation const &);

	virtual int	execute(Network &);

private:
	Client			*_client;
};

std::ostream	&operator<<(std::ostream &, ActionIncantation const &);

#endif /*ACTIONINCANTATION_HEADER*/

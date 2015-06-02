#ifndef ACTIONINCANTATION_HEADER
#define ACTIONINCANTATION_HEADER

#include <string>
#include <iostream>
#include "IAction.hpp"
#include "Client.hpp"

class Client;

class ActionIncantation : public IAction
{
public:
	ActionIncantation(Client *client);
	ActionIncantation(ActionIncantation const &);
	virtual ~ActionIncantation();
	std::string	toString() const;

	ActionIncantation&	operator=(ActionIncantation const &);

	virtual void	execute(Network &network);

private:
	Client			*_client;
};

std::ostream	&operator<<(std::ostream &o, ActionIncantation const &i);

#endif /*ACTIONINCANTATION_HEADER*/

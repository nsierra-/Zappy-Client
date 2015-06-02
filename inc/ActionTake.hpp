#ifndef ACTIONTAKE_HEADER
#define ACTIONTAKE_HEADER

#include <string>
#include <iostream>
#include "IAction.hpp"

class ActionTake : public IAction
{
public:
	ActionTake(const std::string &, Client *);
	ActionTake(ActionTake const &);
	virtual ~ActionTake();
	std::string	toString() const;

	ActionTake&	operator=(ActionTake const &);

	virtual void	execute(Network &network);

private:
	std::string		_obj;
	Client *		_client;
};

std::ostream	&operator<<(std::ostream &o, ActionTake const &i);

#endif /*ACTIONTAKE_HEADER*/

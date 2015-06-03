#ifndef ACTIONTAKE_HEADER
#define ACTIONTAKE_HEADER

# include <string>
# include <iostream>
# include "IAction.hpp"
# include "Inventory.hpp"

class Inventory;

class ActionTake : public IAction
{
public:
	ActionTake(const std::string &, Inventory &);
	ActionTake(ActionTake const &);
	virtual ~ActionTake();
	std::string	toString() const;

	ActionTake&	operator=(ActionTake const &);

	virtual int	execute(Network &network);

private:
	std::string		_obj;
	Inventory &		_inventory;
};

std::ostream	&operator<<(std::ostream &o, ActionTake const &i);

#endif /*ACTIONTAKE_HEADER*/

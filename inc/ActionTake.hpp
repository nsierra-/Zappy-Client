#ifndef ACTIONTAKE_HEADER
#define ACTIONTAKE_HEADER

# include <string>
# include <iostream>
# include "Action.hpp"
# include "Inventory.hpp"

class Inventory;

class ActionTake : public Action
{
public:
	ActionTake(const std::string &, Inventory &);
	ActionTake(ActionTake const &);
	virtual ~ActionTake();
	std::string	toString() const;

	ActionTake	&operator=(ActionTake const &);

	virtual int	execute(Network &);

private:
	std::string		_obj;
	Inventory &		_inventory;
};

std::ostream	&operator<<(std::ostream &, ActionTake const &);

#endif /*ACTIONTAKE_HEADER*/

#ifndef ACTIONDROP_HEADER
#define ACTIONDROP_HEADER

#include <string>
#include <iostream>
#include "Action.hpp"
#include "Inventory.hpp"

class Inventory;

class ActionDrop : public Action
{
public:
	ActionDrop(const std::string &, Inventory &);
	ActionDrop(ActionDrop const &);
	virtual ~ActionDrop();
	std::string	toString() const;

	ActionDrop	&operator=(ActionDrop const &);

	virtual int			execute(Network &);

private:
	const std::string	_object;
	Inventory			&_inventory;
};

std::ostream	&operator<<(std::ostream &, ActionDrop const &);

#endif /*ACTIONDROP_HEADER*/

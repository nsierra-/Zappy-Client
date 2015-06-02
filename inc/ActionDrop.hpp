#ifndef ACTIONDROP_HEADER
#define ACTIONDROP_HEADER

#include <string>
#include <iostream>
#include "IAction.hpp"
#include "Inventory.hpp"

class Inventory;

class ActionDrop : public IAction
{
	public:
		ActionDrop(const std::string &obj, Inventory & inventory);
		ActionDrop(ActionDrop const &);
		virtual ~ActionDrop();
		std::string	toString() const;

		ActionDrop&	operator=(ActionDrop const &);

		virtual void	execute(Network &network);

	private:
		const std::string	_object;
		Inventory			&_inventory;
};

std::ostream	&operator<<(std::ostream &o, ActionDrop const &i);

#endif /*ACTIONDROP_HEADER*/

#ifndef ACTIONBROADCAST_HEADER
#define ACTIONBROADCAST_HEADER

#include <string>
#include <iostream>
#include "IAction.hpp"

class ActionBroadcast : public IAction
{
	public:
		ActionBroadcast(const std::string &);
		ActionBroadcast(ActionBroadcast const &);
		virtual ~ActionBroadcast();
		std::string	toString() const;

		ActionBroadcast&	operator=(ActionBroadcast const &);

		virtual void	execute(Network &network);

	private:
		const std::string		_msg;
};

std::ostream	&operator<<(std::ostream &o, ActionBroadcast const &i);

#endif /*ACTIONBROADCAST_HEADER*/

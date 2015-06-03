#ifndef ACTIONBROADCAST_HEADER
#define ACTIONBROADCAST_HEADER

# include <string>
# include <iostream>
# include "Action.hpp"

class ActionBroadcast : public Action
{
public:
	ActionBroadcast();
	ActionBroadcast(ActionBroadcast const &);
	virtual ~ActionBroadcast();
	std::string	toString() const;

	ActionBroadcast	&operator=(ActionBroadcast const &);

	virtual int			execute(Network &);
	void				setMessage(const std::string &);

private:
	std::string			_msg;
};

std::ostream	&operator<<(std::ostream &o, ActionBroadcast const &i);

#endif /*ACTIONBROADCAST_HEADER*/

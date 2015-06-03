#ifndef ACTIONMOVE_HEADER
#define ACTIONMOVE_HEADER

#include <string>
#include <iostream>
#include "Action.hpp"
#include "eDirection.hpp"

class ActionMove : public Action
{
public:
	ActionMove(enum eDirection = UP);
	ActionMove(ActionMove const &);
	virtual ~ActionMove();
	std::string	toString() const;

	ActionMove	&operator=(ActionMove const &);

	virtual int	execute(Network &network);
	void		setDirection(enum eDirection);

private:
  	static std::map<enum eDirection, std::string>		_directionMap;
	enum eDirection		_dir;
};

std::ostream	&operator<<(std::ostream &, ActionMove const &);

#endif /*ACTIONMOVE_HEADER*/

#include "ActionMove.hpp"

std::map<enum eDirection, std::string>	ActionMove::_directionMap = 
	{
		{ UP,			A_MOVE_FORWARD },
		{ TURN_LEFT,	A_MOVE_LEFT },
		{ TURN_RIGHT,	A_MOVE_RIGHT }
	}
;

ActionMove::ActionMove(enum eDirection dir) :
	_dir(dir)
{

}

ActionMove::ActionMove(ActionMove const &model)
{
	*this = model;
}

ActionMove::~ActionMove()
{

}

std::string	ActionMove::toString() const
{
	return "ActionMove";
}

ActionMove&	ActionMove::operator=(ActionMove const &copy)
{
	if (this != &copy)
		(void)copy;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionMove const &i)
{
	o << i.toString();
	return o;
}

void	ActionMove::execute(Network &network)
{
	network.send(_directionMap[_dir]);
}
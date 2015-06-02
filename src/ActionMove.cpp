#include "ActionMove.hpp"

std::map<enum eDirection, std::string>	ActionMove::_directionMap = 
	{
		{ UP, "avance\n" },
		{ TURN_LEFT, "gauche\n" },
		{ TURN_RIGHT, "droite\n" }
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
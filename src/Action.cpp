//               .-'''''-.
//             .'         `.
//            :             :        File       : Action.cpp
//           :               :       Creation   : 2015-06-02 03:28:49
//           :      _/|      :       Last Edit  : 2015-06-04 00:38:44
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#include "Action.hpp"
#include "Actions.hpp"

const std::string	Action::BROADCAST		= "broadcast ";
const std::string	Action::DROP			= "pose ";
const std::string	Action::EGG				= "fork";
const std::string	Action::EXPULSE			= "expulse";
const std::string	Action::INCANTATION		= "incantation";
const std::string	Action::MOVE_FORWARD	= "avance";
const std::string	Action::MOVE_LEFT		= "gauche";
const std::string	Action::MOVE_RIGHT		= "droite";
const std::string	Action::SEE				= "voir";
const std::string	Action::TAKE			= "prend ";

Client	*Action::client = nullptr;

Action::Action() :
	_successIndex(-1),
	_failIndex(-2)
{

}

void		Action::setSuccessIndex(int n) 		{  _successIndex = n; }
void		Action::setFailureIndex(int n) 		{  _failIndex = n; }
int			Action::getSuccessIndex(void) const	{  return _successIndex; }
int			Action::getFailureIndex(void) const	{  return _failIndex; }

Action		*Action::create(const std::string &action)
{
	if (action == Action::SEE)
		return new ActionSee(Action::client);
	else if (action == Action::EXPULSE)
		return new ActionExpulse();
	else if (action == Action::INCANTATION)
		return new ActionIncantation(Action::client);
	else if (action == Action::EGG)
		return new ActionEgg();
	else if (action == Action::MOVE_FORWARD)
		return new ActionMove(UP);
	else if (action == Action::MOVE_RIGHT)
		return new ActionMove(TURN_RIGHT);
	else if (action == Action::MOVE_LEFT)
		return new ActionMove(TURN_LEFT);
	else if (action == Action::TAKE)
		return new ActionTake(Action::client->getInventory());
	else if (action == Action::DROP)
		return new ActionDrop(Action::client->getInventory());
	else if (action == Action::BROADCAST)
		return new ActionBroadcast();
	return nullptr;
}

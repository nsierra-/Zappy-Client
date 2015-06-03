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

Action::Action() :
	_successIndex(-1),
	_failIndex(-2)
{

}

void		Action::setSuccessIndex(int n) {  _successIndex = n; }
void		Action::setFailureIndex(int n) {  _failIndex = n; }
int			Action::getSuccessIndex(void) 	{  return _successIndex; }
int			Action::getFailureIndex(void) 	{  return _failIndex; }
//               .-'''''-.
//             .'         `.
//            :             :        File       : IAction.cpp
//           :               :       Creation   : 2015-06-02 03:28:49
//           :      _/|      :       Last Edit  : 2015-06-04 00:38:44
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#include "IAction.hpp"

const std::string	IAction::BROADCAST		= "broadcast ";
const std::string	IAction::DROP			= "pose ";
const std::string	IAction::EGG			= "fork";
const std::string	IAction::EXPULSE		= "expulse";
const std::string	IAction::INCANTATION	= "incantation";
const std::string	IAction::MOVE_FORWARD	= "avance";
const std::string	IAction::MOVE_LEFT		= "gauche";
const std::string	IAction::MOVE_RIGHT		= "droite";
const std::string	IAction::SEE			= "voir";
const std::string	IAction::TAKE			= "prend ";

IAction::IAction() :
	_successIndex(-1),
	_failIndex(-2)
{

}

void		IAction::setSuccessIndex(int n) {  _successIndex = n; }
void		IAction::setFailureIndex(int n) {  _failIndex = n; }
int			IAction::getSuccessIndex(void) 	{  return _successIndex; }
int			IAction::getFailureIndex(void) 	{  return _failIndex; }
//               .-'''''-.
//             .'         `.
//            :             :        File       : IAction.hpp
//           :               :       Creation   : 2015-06-02 01:22:19
//           :      _/|      :       Last Edit  : 2015-06-02 20:49:43
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#ifndef IACTION_HPP
# define IACTION_HPP

# include <string>
# include "Network.hpp"

class Network;

class	IAction
{
	public:
		virtual void	execute(Network &network) = 0;

		virtual 		~IAction(void) {};

		static const std::string	BROADCAST;
		static const std::string	DROP;
		static const std::string	EGG;
		static const std::string	EXPULSE;
		static const std::string	INCANTATION;
		static const std::string	MOVE_FORWARD;
		static const std::string	MOVE_LEFT;
		static const std::string	MOVE_RIGHT;
		static const std::string	SEE;
		static const std::string	TAKE;
};

#endif /* IACTION_HPP */
//               .-'''''-.
//             .'         `.
//            :             :        File       : IAction.hpp
//           :               :       Creation   : 2015-06-02 01:22:19
//           :      _/|      :       Last Edit  : 2015-06-02 18:38:11
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

		static const std::string	A_BROADCAST;
		static const std::string	A_DROP;
		static const std::string	A_EGG;
		static const std::string	A_EXPULSE;
		static const std::string	A_INCANTATION;
		static const std::string	A_MOVE_FORWARD;
		static const std::string	A_MOVE_LEFT;
		static const std::string	A_MOVE_RIGHT;
		static const std::string	A_SEE;
		static const std::string	A_TAKE;
};

#endif /* IACTION_HPP */
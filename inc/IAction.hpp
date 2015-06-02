//               .-'''''-.
//             .'         `.
//            :             :        File       : IAction.hpp
//           :               :       Creation   : 2015-06-02 01:22:19
//           :      _/|      :       Last Edit  : 2015-06-02 03:56:50
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#ifndef IACTION_HPP
# define IACTION_HPP
# include "Network.hpp"

class Network;

class	IAction
{
	public:
		virtual void	execute(Network &network) = 0;

		virtual 		~IAction(void) {};
};

#endif /* IACTION_HPP */
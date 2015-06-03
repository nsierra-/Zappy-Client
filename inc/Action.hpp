//               .-'''''-.
//             .'         `.
//            :             :        File       : Action.hpp
//           :               :       Creation   : 2015-06-02 01:22:19
//           :      _/|      :       Last Edit  : 2015-06-04 01:20:29
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#ifndef ACTION_HPP
# define ACTION_HPP

# include <string>
# include "Network.hpp"
# include "Client.hpp"
# include "eDirection.hpp"

class Network;
class Client;

class	Action
{
public:
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

	static Action	*create(const std::string &);

					Action();
	virtual 		~Action(void) {};

	virtual int		execute(Network &) = 0;

	void			setSuccessIndex(int);
	void			setFailureIndex(int);
	int				getSuccessIndex(void) const;
	int				getFailureIndex(void) const;

	static Client	*client;
protected:

	int				_successIndex;
	int				_failIndex;
};

#endif /* ACTION_HPP */

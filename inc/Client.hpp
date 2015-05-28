//               .-'''''-.
//             .'         `.
//            :             :        File       : Client.hpp
//           :               :       Creation   : 2015-05-21 00:43:58
//           :      _/|      :       Last Edit  : 2015-05-29 01:43:18
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs  /-'`  `\   \  \-

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>
# include <map>
# include <regex>
# include <fstream>
# include "Network.hpp"

class	Client
{
	public:
		Client(unsigned int,
				std::string = "Default Team Name",
				std::string = "localhost");
		~Client(void);
		Client(Client const & src);
		Client &operator=(Client const & rhs);

	bool					loop(void);

  private:

  	enum eDirection : int {
  		UP,
  		LEFT,
  		DOWN,
  		RIGHT
  	};

  	static const std::regex			_serverInfosFormat;
	const std::string				_teamName;
	Network							*_network;
	unsigned int					_availableConnections;
	unsigned int					_mapX;
	unsigned int					_mapY;
	std::ofstream 					_ofs;
	std::map<std::string, size_t>	_inventory;

	std::string				_sendTeamInfo(void);
	void					_loadServerInfos(const std::string &);
	void					_forkstem(void);

	/*
	** Actions
	*/
	void					_move(eDirection);
	void					_see(void);
	void					_updateInventory(void);
	void					_take(const std::string &);
	void					_drop(const std::string &);
	void					_expulse(void);
	void					_broadcast(const std::string &);
	void					_spell(void);
	void					_egg(void);
};

#endif /* CLIENT_HPP */
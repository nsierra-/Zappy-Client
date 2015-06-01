//               .-'''''-.
//             .'         `.
//            :             :        File       : Client.hpp
//           :               :       Creation   : 2015-05-21 00:43:58
//           :      _/|      :       Last Edit  : 2015-06-02 01:22:04
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

/*
** TODO NOE
** 
** - constantes pour les noms de pierres, messages du serveur
** - classe IA
** - classe inventaire
*/

class Network;

class	Client
{
	public:

		typedef void (Client::* ActionMan)(const std::smatch &, unsigned int);

		Client(unsigned int,
				std::string = "Default Team Name",
				std::string = "localhost");
		~Client(void);
		Client(Client const & src);
		Client &operator=(Client const & rhs);

	bool					loop(void);
	void					hasDied(void);
	void					recieveBroadcast(const std::string &);

	void					printDebug(const std::string &);

  private:

  	enum eDirection : int {
  		UP,
  		TURN_LEFT,
  		TURN_RIGHT
  	};

  	static const std::regex								_serverInfosFormat;
  	static std::map<enum eDirection, std::string>		_directionMap;
  	static std::vector<std::map<std::string, size_t> >	_totems;

	const std::string				_teamName;
	Network							*_network;
	unsigned int					_level;
	unsigned int					_availableConnections;
	unsigned int					_mapX;
	unsigned int					_mapY;
	std::ofstream 					_ofs;
	std::map<std::string, size_t>	_inventory;
	std::vector<ActionMan>			_actions;
	std::map<std::string, size_t>	_fov; //champ de vision

	std::string				_sendTeamInfo(void);
	void					_loadServerInfos(const std::string &);
	void					_forkstem(void);
	void					_ia(void);

	/*
	** Actions
	*/
	void					_move(enum eDirection);
	void					_see(void);
	void					_updateInventory(void);
	void					_updateInventory(const std::string &, int);
	int						_inInventory(const std::string &, size_t = 1);
	void					_take(const std::string &);
	void					_drop(const std::string &);
	void					_expulse(void);
	void					_broadcast(const std::string &);
	void					_incantation(void);
	void					_egg(void);
	int						_compos(int);
	void					_composFind(int);
	void					_search(void);
	void					_playMove(void);
};

#endif /* CLIENT_HPP */
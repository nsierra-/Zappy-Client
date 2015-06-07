//               .-'''''-.
//             .'         `.
//            :             :        File       : Client.hpp
//           :               :       Creation   : 2015-05-21 00:43:58
//           :      _/|      :       Last Edit  : 2015-06-04 01:49:59
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
# include "Inventory.hpp"
# include "Action.hpp"
# include "eDirection.hpp"

/*
** TODO NOE
**
** - classe IA
*/

class Network;
class Action;

class	Client
{
public:
	Client(unsigned int,
			std::string = "Default Team Name",
			std::string = "localhost");
	~Client(void);
	Client(Client const &);
	Client &operator=(Client const &);

	bool					loop(void);
	void					hasDied(void);
	void					recieveBroadcast(const std::string &);
	Inventory				&getInventory(void);
	unsigned int			getLevel() const;
	void					setLevel(unsigned int);
	void					setPlayerX(size_t &);
	size_t					getPlayerY() const;
	void					setPlayerY(size_t &);
	// Gestion de la map perso beta

	size_t					getPlayerX() const;
	std::map<size_t, std::string>  fov;
	//vector ??
	std::map<size_t, std::map<size_t, std::string> > _map; //inventaire ??

	std::vector<std::map<std::string, size_t> >	getTotems();
	void					printDebug(const std::string &);

private:
	static const std::regex								_serverInfosFormat;
	static std::vector<std::map<std::string, size_t> >	_totems;

	const std::string		_teamName;
	Network					*_network;
	unsigned int			_level;
	unsigned int			_availableConnections;
	unsigned int			_mapX;
	unsigned int			_mapY;
	std::ofstream 			_ofs;
	Inventory				_inventory;
	std::vector<Action *>	_actions;
	size_t					_playerX;
	size_t					_playerY;

	std::string				_sendTeamInfo(void);
	void					_loadServerInfos(const std::string &);
	void					_forkstem(void);
	void					_ia(void);
	int						_compos(int);
	void					_composFind(int);
	int						_search(int);
	void					_playMove(void);
};

#endif /* CLIENT_HPP */

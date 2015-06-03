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
# include "IAction.hpp"
# include "eDirection.hpp"

/*
** TODO NOE
** 
** - classe IA
*/

class Network;
class IAction;

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
	void					hasDied(void);
	void					recieveBroadcast(const std::string &);
	// void					_updateInventory(void);
	// void					_updateInventory(const std::string &, int);

	unsigned int			getLevel() const;
	void					setLevel(unsigned int val);
	// Gestion de la map perso beta

	size_t	_playerX;
	size_t	getplayerX() const;
	void	setplayerX(size_t &val);
	size_t	_playerY;
	size_t	getplayerY() const;
	void	setplayerY(size_t &val);
	std::map<size_t, std::string>  fov;
	//vector ??
	std::map<size_t, std::map<size_t, std::string> > _map; //inventaire ??


	void					printDebug(const std::string &);

  private:

  	static const std::regex								_serverInfosFormat;
  	static std::vector<std::map<std::string, size_t> >	_totems;

	const std::string				_teamName;
	Network							*_network;
	unsigned int					_level;
	unsigned int					_availableConnections;
	unsigned int					_mapX;
	unsigned int					_mapY;
	std::ofstream 					_ofs;
	Inventory						_inventory;
	std::vector<IAction *>			_actions;

	std::string				_sendTeamInfo(void);
	void					_loadServerInfos(const std::string &);
	void					_forkstem(void);
	void					_ia(void);
	int						_compos(int);
	void					_composFind(int);
	void					_search(void);
	void					_playMove(void);

	IAction					*_createAction(const std::string &);
	IAction					*_createAction(enum eDirection);
	IAction					*_createAction(const std::string &, const std::string &);
};

#endif /* CLIENT_HPP */

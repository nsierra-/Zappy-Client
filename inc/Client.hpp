//               .-'''''-.
//             .'         `.
//            :             :        File       : Client.hpp
//           :               :       Creation   : 2015-05-21 00:43:58
//           :      _/|      :       Last Edit  : 2015-05-23 03:26:09
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
  	static const std::regex	_serverInfosFormat;
	const std::string		_teamName;
	Network					*_network;
	unsigned int			_availableConnections;
	unsigned int			_mapX;
	unsigned int			_mapY;
	std::ofstream 			_ofs;
	// unsigned int			_timeRemaining;

	std::string				_sendTeamInfo(void) const;
	void					_loadServerInfos(const std::string &);
	void					_forkstem(void);
};

#endif /* CLIENT_HPP */
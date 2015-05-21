/*             .-'''''-.
			 .'         `.
			:             :   File       : Client.hpp
		   :               :  Creation   : 2015-05-21 00:43:58
		   :      _/|      :  Last Edit  : 2015-05-21 00:44:37
			:   =/_/      :   Author     : nsierra-   
			 `._/ |     .'    Mail       : nsierra-@student.42.fr  
		  (   /  ,|...-'
		   \_/^\/||__
		_/~  `""~`"` \_
	 __/  -'/  `-._ `\_\__
   /jgs  /-'`  `\   \  \-*/

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>
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
	const std::string		_teamName;

	Network					*_network;
};

#endif /* CLIENT_HPP */
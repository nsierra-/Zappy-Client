//               .-'''''-.
//             .'         `.
//            :             :        File       : Network.hpp
//           :               :       Creation   : 2015-05-21 01:03:30
//           :      _/|      :       Last Edit  : 2015-05-29 18:11:35
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs  /-'`  `\   \  \-

#ifndef NETWORK_HPP
# define NETWORK_HPP

# include "Client.hpp"
# include <string>
# include <sys/socket.h>
# include <netinet/in.h>

class 	Client;

class	Network
{
	public:
		Network(Client *, unsigned int, std::string = "localhost");
		~Network(void);
		Network(Network const & src);
		Network &operator=(Network const & rhs);

		bool				isConnected(void);
		std::string			send(const std::string &);
		std::string			recieve(void);
		std::string			getHostName();
		unsigned int		getPort();
		void				close(void);
	private:

		static const size_t	BUFF_SIZE;
		Client				*_client;

		std::string			_hostName;
		unsigned int		_port;
		bool				_connected;
		int					_socket_connect;
		struct sockaddr_in	_sockaddr_connect;
		size_t				_sockaddr_len;

		void				_connect(void);
		
		void				_initConnection(void);
};

#endif /* NETWORK_HPP */
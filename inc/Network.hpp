//               .-'''''-.
//             .'         `.
//            :             :        File       : Network.hpp
//           :               :       Creation   : 2015-05-21 01:03:30
//           :      _/|      :       Last Edit  : 2015-05-21 03:14:34
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs  /-'`  `\   \  \-

#ifndef NETWORK_HPP
# define NETWORK_HPP

# include <string>
# include <sys/socket.h>
# include <netinet/in.h>

class	Network
{
	public:
		Network(unsigned int, std::string = "localhost");
		~Network(void);
		Network(Network const & src);
		Network &operator=(Network const & rhs);

		bool				isConnected(void);
		std::string			send(const std::string &);
		std::string			recieve(void);
		std::string			getHostName();
		unsigned int		getPort();

	private:

		static const size_t	BUFF_SIZE;

		std::string			_hostName;
		unsigned int		_port;
		bool				_connected;
		int					_socket_connect;
		struct sockaddr_in	_sockaddr_connect;
		size_t				_sockaddr_len;

		void				_connect(void);
		void				_close(void);
		void				_initConnection(void);
};

#endif /* NETWORK_HPP */
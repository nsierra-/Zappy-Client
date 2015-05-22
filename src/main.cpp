//               .-'''''-.
//             .'         `.
//            :             :        File       : main.cpp
//           :               :       Creation   : 2015-05-21 01:45:00
//           :      _/|      :       Last Edit  : 2015-05-22 15:11:54
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs  /-'`  `\   \  \-

#include "Client.hpp"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <ctype.h>
#include <stdlib.h>

bool		retrieveOptions(int ac,
							char * const * av,
							std::string &host,
							std::string &team,
							unsigned int &port)
{
	int		c;
	extern char *optarg;

	opterr = 0;
	if (strncmp(av[1], "-n", 2) != 0 || strncmp(av[3], "-p", 2) != 0)
	{
		return false;
	}
	while ((c = getopt(ac, av, ":n:p:h::")) != -1)
	{
		switch (c)
		{
			case 'n':
				team = optarg;
				break ;
			case 'p':
			for( size_t i = 0; i < strlen(optarg); i++)
				if (!isdigit(optarg[i]))
				{
					std::cout << "Please specify a port using -p" << std::endl;
					return false;
				}
				port = atoi(optarg);
				break ;
			case 'h':
				host = optarg;
				break ;
			case '?':
				std::cout << "dfko''oingjkdfbghiprbvjekjv;bkr" << std::endl;
				if (optopt == 'n')
					std::cout << "Please specify a team name using -n" << std::endl;
				else if (optopt == 'p')
					std::cout << "Please specify a port using -p" << std::endl;
				else
					std::cout << "Unknown option : " << (char)optopt << std::endl;
				return false;
			default:
				abort();
		}
	}
	return true;
}

int			main(int ac, char * const * av)
{
	std::string		host;
	std::string		team;
	unsigned int	port;

	host = "127.0.0.1";
	if (ac < 5 || !retrieveOptions(ac, av, host, team, port))
	{
		std::cout << "Usage: ./client -n <team> -p <port> [-h <hostname>]" << std::endl;
		return 0;
	}
	Client	c(port, team, host);
	return c.loop();
}
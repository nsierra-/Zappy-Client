//               .-'''''-.
//             .'         `.
//            :             :        File       : main.cpp
//           :               :       Creation   : 2015-05-21 01:45:00
//           :      _/|      :       Last Edit  : 2015-05-21 02:46:47
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs  /-'`  `\   \  \-

#include "Client.hpp"
#include <stdlib.h>
#include <iostream>

int			main(int ac, const char ** av)
{
	if (ac != 4)
	{
		std::cout << "EHO" << std::endl;
		return 0;
	}

	Client	c(atoi(av[1]), av[2], av[3]);

	return c.loop();
}
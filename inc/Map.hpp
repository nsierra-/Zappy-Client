//               .-'''''-.
//             .'         `.
//            :             :        File       : Map.hpp
//           :               :       Creation   : 2015-06-08 00:57:04
//           :      _/|      :       Last Edit  : 2015-06-08 01:21:33
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#ifndef MAP_HPP
# define MAP_HPP

# include <string>
# include <iostream>
# include <vector>
# include "Inventory.hpp"

class Inventory;

class Map
{
public:
	Map(size_t = 0, size_t = 0);
	~Map();
	Map(Map const &);

	std::string	toString() const;
	Map &	operator=(Map const &);

private:
	std::vector<std::vector<Inventory> >	_data;
};

std::ostream	&operator<<(std::ostream &o, Map const &i);

#endif /*MAP_HPP */
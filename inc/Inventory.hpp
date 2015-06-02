//               .-'''''-.
//             .'         `.
//            :             :        File       : Inventory.hpp
//           :               :       Creation   : 2015-06-02 18:57:56
//           :      _/|      :       Last Edit  : 2015-06-02 20:02:04
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <string>
#include <iostream>
#include <map>

class Inventory
{
public:
	Inventory();
	~Inventory();
	Inventory(Inventory const &);

	std::string	toString() const;
	Inventory&	operator=(Inventory const &);
	size_t 		operator[](const std::string &);

	bool	has(const std::string &, size_t = 1);
	void	add(const std::string &, int = 1);

private:
	std::map<std::string, size_t>	_data;
};

std::ostream	&operator<<(std::ostream &o, Inventory const &i);

#endif /*INVENTORY_HPP*/
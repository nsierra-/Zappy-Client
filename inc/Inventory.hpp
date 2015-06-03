//               .-'''''-.
//             .'         `.
//            :             :        File       : Inventory.hpp
//           :               :       Creation   : 2015-06-02 18:57:56
//           :      _/|      :       Last Edit  : 2015-06-04 01:31:25
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
	Inventory	&operator=(Inventory const &);
	size_t 		operator[](const std::string &);

	static const std::string	LINEMATE;
	static const std::string	DERAUMERE;
	static const std::string	SIBUR;
	static const std::string	MENDIANE;
	static const std::string	PHIRAS;
	static const std::string	THYSTAME;
	static const std::string	FOOD;

	bool	has(const std::string &, size_t = 1);
	void	add(const std::string &, int = 1);
	void	set(const std::string &, size_t);

private:
	std::map<std::string, size_t>	_data;
};

std::ostream	&operator<<(std::ostream &, Inventory const &);

#endif /*INVENTORY_HPP*/

//               .-'''''-.
//             .'         `.
//            :             :        File       : Inventory.cpp
//           :               :       Creation   : 2015-06-02 18:59:27
//           :      _/|      :       Last Edit  : 2015-06-02 20:11:54
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs     /-'`  `\   \  \-

#include "Inventory.hpp"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}

Inventory::Inventory(Inventory const & rhs)
{
	*this = rhs;
}

Inventory&	Inventory::operator=(Inventory const & rhs)
{
	if (this != &rhs)
		(void)rhs;
	return *this;
}

size_t 		Inventory::operator[](const std::string & obj)
{
	try {
		return _data.at(obj);
	} catch (const std::out_of_range & oor) {
		return 0;
	}
}

std::string	Inventory::toString() const
{
	return "Inventory";
}

std::ostream	&operator<<(std::ostream &o, Inventory const &i)
{
	o << i.toString();
	return o;
}

bool	Inventory::has(const std::string & obj, size_t qty)
{
	try {
		return _data.at(obj) == qty;
	} catch (const std::out_of_range &oor) {
		return false;		
	}
}

void	Inventory::add(const std::string & obj, int qty)
{
	size_t	prevQty;

	try {
		prevQty = _data.at(obj);
	} catch (const std::out_of_range &oor) {
		prevQty = 0;
	}

	_data[obj] = prevQty + qty;

	if (_data.at(obj) == 0)
		_data.erase(obj);
}
#include "ActionSee.hpp"

ActionSee::ActionSee(Client *client) :
	_client(client)
{

}

ActionSee::ActionSee(ActionSee const &model)
{
	*this = model;
}

ActionSee::~ActionSee()
{

}

std::string		ActionSee::toString() const
{
	return "ActionSee";
}

ActionSee		&ActionSee::operator=(ActionSee const &copy)
{
	if (this != &copy)
		_client = copy._client;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ActionSee const &i)
{
	o << i.toString();
	return o;
}

int				ActionSee::execute(Network &network)
{
	std::string ret;
	std::string tmp;
	int i = 0;

	ret = network.send(SEE);
	try
	{
		std::regex re("([\\w \\s]*)[,}]");
		std::sregex_iterator next(ret.begin(), ret.end(), re);
		std::sregex_iterator end;

		while (next != end)
		{
			std::smatch match = *next;
			tmp = match.str();
			if (tmp[0] == ' ')
				tmp = match.str().substr(1);
			tmp.resize(tmp.size() - 1);
			//add to map
			_client->fov[i] = tmp;
			next++;
			i++;
		}

		return _successIndex;
	}
	catch (std::regex_error& e)
	{ }
	return _failIndex;
	/*
	parse du retour en n string/inventaire
	getplayerX/Y
	set map[X][Y] = parse[0]
	....
	set map[X + ?][Y + ?] = parse[?]
	*/
	//si nourriture case 0 add prend nourriture
}

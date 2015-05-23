//               .-'''''-.
//             .'         `.
//            :             :        File       : ErrorMsg.hpp
//           :               :       Creation   : 2015-05-22 23:38:30
//           :      _/|      :       Last Edit  : 2015-05-23 03:35:20
//            :   =/_/      :        Author     : nsierra-
//             `._/ |     .'         Mail       : nsierra-@student.42.fr
//          (   /  ,|...-'
//           \_/^\/||__
//        _/~  `""~`"` \_
//     __/  -'/  `-._ `\_\__
//   /jgs  /-'`  `\   \  \-

#ifndef ERRORMSG_HPP
# define ERRORMSG_HPP

# include <string>

static const std::string E_UNUSUAL_SERVER_BEHAVIOR = "Server seems odd... Aborting.";
static const std::string E_SOCKET_CREATION = "Socket creation error !";
static const std::string E_SOCKET_CONNECTION = "Socket connection error !\n";
static const std::string E_FORK = "Fork error. Aborting.";

#endif /* ERRORMSG_HPP */
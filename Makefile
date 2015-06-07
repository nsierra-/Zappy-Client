#               .-'''''-.
#             .'         `.
#            :             :   File       : Makefile
#           :               :  Creation   : 2015-05-17 02:38:33
#           :      _/|      :  Last Edit  : 2015-06-02 19:12:09
#            :   =/_/      :   Author     : nsierra-
#             `._/ |     .'    Mail       : nsierra-@student.42.fr
#          (   /  ,|...-'
#           \_/^\/||__
#        _/~  `""~`"` \_
#     __/  -'/  `-._ `\_\__
#   /jgs  /-'`  `\   \  \--\

NAME				=	client

SRC_DIR				=	src/
INC_DIR				=	inc/

CLASS_SRC_SUFFIX	=	.cpp
CLASS_INC_SUFFIX	=	.hpp
CLASSES				=	Inventory \
						Client \
						Network \
						ActionBroadcast \
						ActionDrop \
						ActionEgg \
						ActionExpulse \
						ActionIncantation \
						ActionMove \
						ActionSee \
						ActionTake

INTERF_SRC_SUFFIX	=	.cpp
INTERF_INC_SUFFIX	=	.hpp
INTERFACES			=

ABSTR_SRC_SUFFIX	=	.cpp
ABSTR_INC_SUFFIX	=	.hpp
ABSTRACTS			=	Action

TEMPL_SRC_SUFFIX	=	.cpp
TEMPL_INC_SUFFIX	=	.hpp
TEMPLATES			=

INC_FILES			=	$(addsuffix $(CLASS_INC_SUFFIX), $(CLASSES))		\
						$(addsuffix $(INTERF_INC_SUFFIX), $(INTERFACES))	\
						$(addsuffix $(ABSTR_INC_SUFFIX), $(ABSTRACTS))		\
						$(addsuffix $(TEMPL_INC_SUFFIX), $(TEMPLATES)) 		\
						ErrorMsg.hpp \
						Actions.hpp \
						eDirection.hpp

SRC_FILES			=	$(addsuffix $(CLASS_SRC_SUFFIX), $(CLASSES))		\
						$(addsuffix $(INTERF_SRC_SUFFIX), $(INTERFACES))	\
						$(addsuffix $(ABSTR_SRC_SUFFIX), $(ABSTRACTS))		\
						$(addsuffix $(TEMPL_SRC_SUFFIX), $(TEMPLATES))		\
						main.cpp


SRC					=	$(addprefix $(SRC_DIR), $(SRC_FILES))
INC					=	$(addprefix $(INC_DIR), $(INC_FILES))
OBJ					=	$(SRC:.cpp=.o)

CC					=	clang++
MAKE				=	make

CFLAGS				=	-Wall -Wextra -Werror -std=c++11 -stdlib=libc++ -g3
IFLAGS				=	-I./$(INC_DIR)
LDFLAGS				=

$(NAME):			$(INC) $(OBJ)
					$(CC) $(LDFLAGS) $(OBJ) -o $@

all:				$(NAME)

%.o:				%.cpp
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
					rm -f $(OBJ)

fclean:
					rm -f $(OBJ)
					rm -f $(NAME)

re:					fclean all

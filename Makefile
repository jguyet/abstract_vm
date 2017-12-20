# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/25 15:18:38 by jguyet            #+#    #+#              #
#    Updated: 2017/03/19 04:47:40 by jguyet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STUDENT		=	jguyet

AUTHOR		=	auteur

PROG1		=	avm

PROJECT_TYPE=	cpp

NAMEBASE    =   $(shell basename $(PROG1) .a)

LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`

MAX_COLS	=	$$(echo "$$(tput cols)-21-$(LENGTHNAME)"|bc)

CC			=	g++

FLAGS		=	-Wall -Wextra -Werror -std=c++11

OBJDIR		=	.objs/

INCDIR		=	srcs/

SRCSPROG1	=	\
				srcs/main.cpp																\
				srcs/Float.cpp																\
				srcs/Double.cpp																\
				srcs/Int8.cpp																\
				srcs/Int16.cpp																\
				srcs/Int32.cpp																\
				srcs/Int64.cpp																\
				srcs/OperandFactory.cpp														\
				srcs/AbstractVmHandler.cpp													\
				srcs/AbstractVmParser.cpp													\
				srcs/split.cpp																\
				srcs/strtoupper.cpp


OBJSPROG1	=	$(addprefix $(OBJDIR), $(SRCSPROG1:.$(PROJECT_TYPE)=.o))

.SILENT:

all:
	##if test ! -f $(AUTHOR) ; then															\
	##	echo "$(STUDENT)" > $(AUTHOR);														\
	##fi
	if test -f $(PROG1) ; then																\
		echo "make: Nothing to be done for \`all\`.";										\
	else																					\
		$(MAKE) -j $(STUDENT);																\
	fi

$(STUDENT):
	$(MAKE) $(PROG1)

$(PROG1):	$(OBJDIR) $(OBJSPROG1)
	$(CC) $(FLAGS) -o $(PROG1) $(OBJSPROG1)
	echo "MAKE    [$(PROG1)]"
	echo "\033[38;5;227mAUTHOR  :\033[0m"
	cat -e $(AUTHOR)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	mkdir -p $(dir $(OBJSPROG1))

$(OBJDIR)%.o : %.$(PROJECT_TYPE) | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@																\
		-I $(INCDIR)
	printf "\r\033[38;5;117m%s\033[38;5;092m%*.*s\033[0m\033[K"								\
	"MAKE    "$(NAMEBASE)" plz wait ..."	$(MAX_COLS)	$(MAX_COLS)	"[$(@)]"

clean:
	echo -en "\r\033[38;5;101mCLEAN  "														\
		"[\033[0m$(NAMEBASE)\033[38;5;101m]\033[K\033[0m";									\
	rm -rf $(OBJDIR)

fclean:
	echo -en "\r\033[38;5;124mFCLEAN "														\
		"[\033[0m$(NAMEBASE)\033[38;5;124m]\033[K\033[0m";									\
	rm -rf $(PROG1)
	rm -rf $(OBJDIR)

re:			fclean all

version:
	echo "c++11"

.PHONY: all clean fclean re

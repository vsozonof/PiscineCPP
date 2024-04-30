# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:09:59 by vsozonof          #+#    #+#              #
#    Updated: 2024/04/30 15:52:11 by vsozonof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CCC = c++
CPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	   Zombie.cpp \
	   newZombie.cpp \
	   randomChump.cpp \

DEPS = Zombie.hpp \



OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CCC) $(CPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(DEPS)
	$(CCC) $(CPFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: 
		$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
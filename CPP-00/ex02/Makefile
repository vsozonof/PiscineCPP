# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:09:59 by vsozonof          #+#    #+#              #
#    Updated: 2024/04/30 14:54:15 by vsozonof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

CCC = c++
CPFLAGS = -Wall -Werror -Wextra -std=c++98

BL=\033[1;34m
GR=\033[1;32m
OR=\033[1;33m
RD=\033[1;31m
WH=\033[0m

SRCS = tests.cpp \
	   Account.cpp \

DEPS = Account.hpp \



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
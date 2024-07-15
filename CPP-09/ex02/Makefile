# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:09:59 by vsozonof          #+#    #+#              #
#    Updated: 2024/07/15 08:38:37 by vsozonof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	   PmergeMe.cpp \
	   
DEPS = PmergeMe.hpp \

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(DEPS)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: 
		$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:09:59 by vsozonof          #+#    #+#              #
#    Updated: 2024/07/08 10:11:40 by vsozonof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	   Base.cpp \
	   
DEPS = Base.hpp \
	   A.hpp \
	   B.hpp \
	   C.hpp \



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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:09:59 by vsozonof          #+#    #+#              #
#    Updated: 2024/07/08 03:43:50 by vsozonof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	   Bureaucrat/Bureaucrat.cpp \
	   AForm/AForm.cpp \
	   SchrubberyCreationForm/SchrubberyCreationForm.cpp \
	   RobotomyRequestForm/RobotomyRequestForm.cpp \
	   PresidentialPardonForm/PresidentialPardonForm.cpp \
	   Intern/Intern.cpp \

DEPS = Bureaucrat/Bureaucrat.hpp\
	   AForm/AForm.hpp \
	   SchrubberyCreationForm/SchrubberyCreationForm.hpp \
	   RobotomyRequestForm/RobotomyRequestForm.hpp \
	   PresidentialPardonForm/PresidentialPardonForm.hpp \
	   Intern/Intern.hpp \

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
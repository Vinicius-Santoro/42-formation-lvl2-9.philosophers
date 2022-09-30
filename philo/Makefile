# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:21:12 by vnazioze          #+#    #+#              #
#    Updated: 2022/09/29 20:21:12 by vnazioze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
HEADER	=	philo.h

INCLUDE        =    -I ./includes

CC            =    gcc -Wall -Wextra -Werror -g -pthread
RM            =    rm -f

SRC_PATH    =    ./src/
OBJ_PATH    =    ./obj/

SRC_FILES    =	main.c \
				free.c \
				thread.c \
				ft_atoi.c \
				init_list.c \
				death_check.c \
				philo_actions.c 

SRC            =    $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ            =    $(addprefix $(OBJ_PATH),$(subst .c,.o,$(SRC_FILES)))

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				mkdir -p $(OBJ_PATH)
				$(CC) $(INCLUDE) -c $< -o $@

all:            $(NAME)

$(NAME):        $(LIBFT) $(PRINTF) $(OBJ)
				$(CC) -o $(NAME) $(OBJ)
		
clean:
				$(RM) $(OBJ)

fclean:            clean
				$(RM) $(NAME) rm -rf $(OBJ_PATH)

re:				fclean all

.PHONY:			all, clean, fclean, re

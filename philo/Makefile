# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 13:06:05 by vnazioze          #+#    #+#              #
#    Updated: 2022/10/13 13:06:05 by vnazioze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME			=	philo
HEADER			=	philo.h

INCLUDE        	=    -I ./includes

CC            	=    gcc -Wall -Wextra -Werror -g -pthread
RM            	=    rm -f

SRC_PATH    	=    ./src/
OBJ_PATH    	=    ./obj/

SRC_FILES    	=	main.c \
					utils.c \
					philo_actions.c\
					free.c \
					death_check.c \
					thread.c\
					init_list.c \
					mutex_check.c

SRC            	=    $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ            	=    $(addprefix $(OBJ_PATH),$(subst .c,.o,$(SRC_FILES)))

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				mkdir -p $(OBJ_PATH)
				$(CC) $(INCLUDE) -c $< -o $@

all:            $(NAME)

$(NAME):        $(OBJ)
				$(CC) -o $(NAME) $(OBJ)
				@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
		
clean:
				$(RM) rm -rf $(OBJ_PATH)
				@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean:            clean
				$(RM) $(NAME) rm -rf $(OBJ_PATH)
				@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:				fclean all

.PHONY:			all, clean, fclean, re
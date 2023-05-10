# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 21:11:53 by donghyk2          #+#    #+#              #
#    Updated: 2023/02/25 19:57:33 by donghyk2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS_NAME		= checker

CC				= @cc
CFLAGS			= -Wall -Werror -Wextra
LIBFT			= -Lsrc/libft -lft
GNL_DIR			= src/get_next_line/
MAN_DIR			= mandatory/
BONUS_DIR		= bonus/

SRC				= main.c arg_check.c mod_lib.c mod_lib2.c mod_lib3.c node.c stack_func.c \
				push_command.c swap_command.c rotate_command.c rev_rotate_command.c \
				hard_coding.c greedy.c sum_rotate_command.c greedy2.c

BONUS_SRC		= main_bonus.c arg_check_bonus.c mod_lib_bonus.c mod_lib2_bonus.c mod_lib3_bonus.c node_bonus.c stack_func_bonus.c \
				push_command_bonus.c swap_command_bonus.c rotate_command_bonus.c rev_rotate_command_bonus.c \
				checker_bonus.c

GNL				= get_next_line.c get_next_line_utils.c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

GNL_OBJS		= $(addprefix $(GNL_DIR), $(GNL:.c=.o))
OBJS			= $(addprefix $(MAN_DIR), $(SRC:.c=.o))
BONUS_OBJS		= $(addprefix $(BONUS_DIR), $(BONUS_SRC:.c=.o))

$(NAME): $(OBJS)
	@make -sC src/libft all
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $@


$(BONUS_NAME): $(GNL_OBJS) $(BONUS_OBJS)
	@make -sC src/libft all
	$(CC) $(CFLAGS) $(LIBFT) $(GNL_OBJS) $(BONUS_OBJS) -o $@



bonus: $(BONUS_NAME)

clean:
	@make -C src/libft clean
	@rm -f $(GNL_OBJS)
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)

fclean:
	@make -C src/libft fclean
	@make clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re bonus

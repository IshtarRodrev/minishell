# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/24 18:05:15 by farhanmasfi       #+#    #+#              #
#    Updated: 2026/07/24 21:35:15 by farhanmasfi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

HEADER		= minishell.h

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= src/main.c \
			  src/execution/execute.c

OBJS		= $(SRCS:.c=.o)

# readline sits in different places on macOS and Linux
UNAME		:= $(shell uname)
ifeq ($(UNAME), Darwin)
	RL_DIR	= $(shell brew --prefix readline)
	CFLAGS	+= -I$(RL_DIR)/include
	LDFLAGS	+= -L$(RL_DIR)/lib
endif

LDLIBS		= -lreadline

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


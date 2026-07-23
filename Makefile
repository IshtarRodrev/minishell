NAME = minishell.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADER = minishell.h

LIBFT_FOLDER = libft
LIBFT_LIB = $(LIBFT_FOLDER)/libft.a

SRCS = file1.c \
	file2.c \
	file3.c \
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re #test debug

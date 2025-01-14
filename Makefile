CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
input_handler.c input_handler_2.c input_handler_3.c input_handler_4.c \
move.c move_2.c move_3.c sort.c sort_2.c sort_3.c sort_4.c sort_5.c

HEADERS = ft_push_swap.h libft.h

LIBFT = libft.a

OBJ_FILES = $(SRC:.c=.o)

NAME = push_swap.out

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRC) $(HEADER) $(LIBFT) -o $(NAME)

clean: 
		rm -f $(OBJ_FILES)

fclean:clean
		rm -f $(NAME)

re: fclean all

.PHONY :all clean fclean re

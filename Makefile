CC = cc 

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
input_handler.c input_handler_2.c input_handler_3.c input_handler_4.c \
move.c move_2.c move_3.c sort_1.c  sort_2.c sort_3.c double_linked_list.c print_any_list.c \
init_stack.c algo_utils.c calcule_destination.c choose_sens.c nbr_moove.c \
refresh_stack_moove.c send_correct_number.c push_back.c

LIBFT = -Llibft -lft

OBJ_FILES = $(SRC:.c=.o)

NAME = push_swap

all: lib $(NAME)

$(NAME): $(OBJ_FILES)
		$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

clean: 
		rm -f $(OBJ_FILES)

fclean:clean
		rm -f $(NAME)
		
lib:
	@make fclean -C libft > /dev/null 2>&1
	@make -C libft > /dev/null 2>&1

re: fclean all

.PHONY :all clean fclean re

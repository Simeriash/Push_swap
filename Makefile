NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror -g

HEADER := push_swap.h

LIBFT := src/libft/libft.a


SOURCES := ft_push_swap.c ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c ft_make_list.c ft_split_ps.c ft_atoi_ps.c ft_format_stack.c ft_sort_stack.c ft_sort_stack_utils.c


SRC_DIR := src/
SRC := $(addprefix $(SRC_DIR), $(SOURCES))

OBJ_DIR := obj/
OBJ := $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))


.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ)
	$(MAKE) -C src/libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean : 
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C src/libft -B clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C src/libft -B fclean

re : fclean all

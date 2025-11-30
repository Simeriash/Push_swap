CC := cc

CFLAGS := -Wall -Wextra -Werror -g

LIBFT_DIR := libft/

SOURCES_LIB := ft_strlen.c ft_isdigit.c ft_substr.c

SOURCES := $(addprefix $(LIBFT_DIR), $(SOURCES_LIB))\
		ft_push_swap.c ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c ft_make_list.c ft_split_ps.c ft_atoi_ps.c

OBJ_DIR := objects/

OBJECTS := $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

HEADER := push_swap.h

NAME := push_swap

.PHONY : all clean fclean re

all : $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)$(LIBFT_DIR)

$(OBJ_DIR)%.o : %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME) : $(OBJ_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean :
	rm -rf $(OBJECTS)
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all
